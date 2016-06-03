MEMORY
{
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    ram_vt (rwx) : ORIGIN = 0x20000000, LENGTH = 0x200
    ram (rwx) : ORIGIN = 0x20000200, LENGTH = 20K - 0x200
}

/* Enforce emission of the vector table. */
EXTERN (vector_table)

ENTRY(reset_handler)

SECTIONS
{
    .vectors : {
        *(.data.vector_table)
        . = ALIGN(4);
    } > ram_vt

    .text : {
	*(.text.reset_handler)
        . = ALIGN(4);
        *(.text*)
        . = ALIGN(4);
    } > ram

    .data : {
	_data = .;
	*(.data*)
	. = ALIGN(4);
	_edata = .;
    } > ram
    _data_loadaddr = LOADADDR(.data);

    .bss : {
	*(.bss*)
	*(COMMON)
	_ebss = .;
	. = ALIGN(4);
    } > ram

    . = ALIGN(4);
    end = .;
}

PROVIDE(_stack = ORIGIN(ram) + LENGTH(ram));
