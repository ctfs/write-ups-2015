int main() {
    // fld qword [0x8048690] == push 32 float number from content of 0x8048690 to the FPU registers (st0)
    // content is now st0            64,333330000000003678906068671494722     (raw 0x400580aaaa3ad18d2800) 
    // in hex: gdb-peda$ x/20wx 0x8048690: 0x8048690:      0x475a31a5      0x40501555      0x3b031b01      0x00000028
    // https://en.wikibooks.org/wiki/X86_Disassembly/Floating_Point_Numbers
    // fstp move content of st0 to esp+0x98, which is right in front of rip_main?
    char* buf = esp[esp+0x18]; // 0x0
    setvbuf(stdout, 0x0, 0x2, 0x0);
    printf("Buff: %p\n", &buf); // TODO
    __isoc99_scanf("%s", &buf);
    // load 32 float from esp+0x98
    // load 32 float from 0x8048690
    // fucompi st(1) == fucomip st(0), st(1) == unordered compare two floating-point (fu), (com) set eflags (i) and pop (p) - saves result in eflags and st7
    // save st0 in st7, moving it
    // if parity bit is set, meaning result of comparing value from stack and address 0x8048690 is uneven, then exit
    if(jp) {
        puts("Nope");
        exit(1);
    }
    // repeat the load operations and comparing
    // if je is not taken, meaning zero bit is not set after comparing operation, and therefore both values are not equal, exit again
    if (!je) {
        puts("Nope");
        exit(1);
    }
    printf("Got %s", &buf);
}
