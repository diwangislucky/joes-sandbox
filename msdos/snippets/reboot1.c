#include <dos.h>
main()
{
int tmp;
disable();
*((unsigned long far *)0x0000004c)=0xc80001cf;
enable();
up:
_ES=0;
_AX=0x0201;
_CX=0x0001;
_DX=0x0000;
_BX=0x7c00;
geninterrupt(0x13);
tmp=_FLAGS;
if(tmp&1) goto up;
__emit__(0xea,0x00,0x7c,0x00,0x00);
}
