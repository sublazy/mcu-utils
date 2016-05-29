MEMORY
{
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 128K
    ram_vt (rwx) : ORIGIN = 0x20000000, LENGTH = 0x200
    ram (rwx) : ORIGIN = 0x20000200, LENGTH = 20K - 0x200
}

ENTRY(reset_handler)

SECTIONS
{
    .text.vectors : {
        *(.text.vectors*)
        . = ALIGN(4);
    } > ram_vt

    .text : {
        *(.text*)
        . = ALIGN(4);
    } > ram

    .data : {
	_data = .;
	*(.data*)
	_edata = .;
    } > ram
    _data_loadaddr = LOADADDR(.data);

    .bss : {
	*(.bss*)
	_ebss = .;
    } > ram

}
