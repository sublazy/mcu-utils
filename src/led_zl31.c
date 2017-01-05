// TODO this file should be generated from zl31.xml
#include "led.h"
#include "led_zl31.h"

void led_platform_init(void)
{
	bool active_low = true;
	led_new(GPIOB, GPIO1, active_low);
	led_new(GPIOB, GPIO2, active_low);
}

//led_t *
