#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#define RCC_REG(i)    MMIO32(RCC_BASE + ((i) >> 5))
#define RCC_BIT(i)	(1 << ((i) & 0x1f))

#define UART_PORT     GPIOA
#define UART_PIN_TX   GPIO9
#define UART_PIN_RX   GPIO10

void delay(uint32_t delay);
static char get_char(void);
static int is_char_incoming(void);

void delay(uint32_t delay)
{
	volatile uint32_t d = delay;
	while(d--);
}

static void uart_init(void)
{
	RCC_REG(RCC_USART1) |= RCC_BIT(RCC_USART1);
	RCC_REG(RCC_GPIOA) |= RCC_BIT(RCC_GPIOA);
	RCC_REG(RCC_AFIO) |= RCC_BIT(RCC_AFIO);

	GPIO_CRH(UART_PORT) =
		(GPIO_MODE_OUTPUT_2_MHZ << 4) |
		(GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	<< 6) |
		(GPIO_MODE_OUTPUT_2_MHZ << 8) |
		(GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	<< 10) ;

	USART_CR1(USART1) =
		USART_CR1_RE |
		USART_CR1_TE ;

	USART_CR2(USART1) =
		USART_CR2_STOPBITS_1;

	uint32_t usart_clk = 8000000;
	uint32_t baud = 115200;

	USART_BRR(USART1) = ((2 * usart_clk) + baud) / (2 * baud);

	USART_CR1(USART1) |= USART_CR1_UE;
}

static bool is_uart_tx_busy (uint32_t uart)
{
	if (USART_SR(uart) & USART_SR_TXE)
		return false;
	else
		return true;
}

static char get_char()
{
	return (USART_DR(USART1));
}

static void put_char(char c)
{
	while (is_uart_tx_busy(USART1))
		;
	USART_DR(USART1) = c;
}

static int is_char_incoming()
{
	return (USART_SR(USART1) & USART_SR_RXNE);
}

int main(void)
{
	RCC_REG(RCC_GPIOB) |= RCC_BIT(RCC_GPIOB);

	GPIO_CRL(GPIOB) &= ~0xFF0;
	GPIO_CRL(GPIOB) |=
		(GPIO_MODE_OUTPUT_2_MHZ << 8) |
		(GPIO_MODE_OUTPUT_2_MHZ << 4);

	GPIO_BSRR(GPIOB) |= 0x6;

	uart_init();

	for (int i = 0; i < 9; i++) {
		GPIO_BSRR(GPIOB) |= 0x4;
		delay(50000);
		GPIO_BRR(GPIOB) |= 0x4;
		delay(50000);
	}

	while (1) {
		GPIO_BSRR(GPIOB) |= 0x6;

		if (is_char_incoming()) {
			GPIO_BRR(GPIOB) |= 0x6;
			char c = get_char();
			put_char(c);
		}
	}
	return 0;
}
