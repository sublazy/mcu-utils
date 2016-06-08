/*------------------------------------------------------------------------*/
/* Universal string handler for user console interface  (C)ChaN, 2011     */
/*------------------------------------------------------------------------*/

#ifndef XPRINTF_H
#define XPRINTF_H

#include "headers_all.h"

#define _USE_XFUNC_OUT  1       /* 1: Use output functions */
#define _CR_CRLF        1       /* 1: Convert \n ==> \r\n in the output char */

#define _USE_XFUNC_IN   0       /* 1: Use input function */
#define _LINE_ECHO      1       /* 1: Echo back input chars in xgets function */


#if !defined (PROJ_CFG_STD_PRINTF)
#define PROJ_CFG_STD_PRINTF	0
#define PROJ_CFG_OWN_PRINTF    (!PROJ_CFG_STD_PRINTF)
#endif

#if _USE_XFUNC_OUT
#define xdev_out(func) xfunc_out = (void(*)(unsigned char))(func)
extern void (*xfunc_out)(unsigned char);
void xputc (char c);
void xputs (const char* str);
void xfputs (void (*func)(unsigned char), const char* str);
void xprintf (const char* fmt, ...);
void xsprintf (char* buff, const char* fmt, ...);
void xfprintf (void (*func)(unsigned char), const char*	fmt, ...);
void put_dump (const void* buff, unsigned long addr, int len, int width);
#define DW_CHAR		sizeof(char)
#define DW_SHORT	sizeof(short)
#define DW_LONG		sizeof(long)
#endif

#if _USE_XFUNC_IN
#define xdev_in(func) xfunc_in = (unsigned char(*)(void))(func)
extern unsigned char (*xfunc_in)(void);
int xgets (char* buff, int len);
int xfgets (unsigned char (*func)(void), char* buff, int len);
int xatoi (char** str, long* res);
#endif


#if IS_ENABLED (PROJ_CFG_OWN_PRINTF)
#ifdef putc
#undef putc
#define putc    xputc
#endif

#define puts	xputs
#define fputs	xfputs
#define printf  xprintf
#define sprintf xsprintf
#define fprintf xfprintf
#else
#endif // IS_ENABLED (PROJ_CFG_OWN_PRINTF)

#endif // XPRINTF_H
