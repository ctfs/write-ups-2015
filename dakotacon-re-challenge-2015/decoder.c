#include <stdio.h>
#include <inttypes.h>
#include <string.h>

uint16_t rotate_left(uint16_t num, uint16_t bits)
{
  return ((num << bits) | (num >> (16 -bits)));
} 

uint16_t rotate_right(uint16_t num, uint16_t bits)
{
  return ((num >> bits) | (num << (16 -bits)));
}

int main(void)
{
    /* String to which our input is compared, as it appears in memory. */
    char buf[] = "\x96\xd6\x86\xc6" \
                "\xab\x7b\x73\x99" \
                "\xc0\xcc\xd0\xad" \
                "\xca\xd0\x84\xbe" \
                "\x67\x69\x65\x67" \
                "\xba\x39\xa3\xaf" \
                "\xd8\x5b\x17\xdd" \
                "\xae\xc8\xae\x4c" \
                "\x06\x74\xd6\x16" \
                "\x4b\x63\x73\x19" \
                "\xbd\xb5\x00\x00";

    int r = 12; // Rotation counter.
    int i = 0; // Index into array.
    uint16_t tmp = 0; // tmp variable to hold values with which we are mucking.
    /*
    .text:0123114D mov     ecx, 12
    .text:01231152
    .text:01231152 loc_1231152:                            ; CODE XREF: _main+DEj
    .text:01231152 mov     dx, [eax] // eax holds a pointer to the user-input.
    .text:01231155 rol     dx, cl    // cl is equivalent to our 'r' variable.
    .text:01231158 mov     [eax], dx
    .text:0123115B add     eax, 2
    .text:0123115E mov     dx, [eax]
    .text:01231161 rol     dx, cl
    .text:01231164 mov     [eax], dx
    .text:01231167 add     eax, 2
    .text:0123116A dec     ecx
    .text:0123116B cmp     ecx, 0
    .text:0123116E jge     short loc_1231152 */

    /* The above comment is the encoding algorithm, in assembly. The following code
     * is the algorithmic inverse. */

    for (r = 12; r > 0; r--) // Start rotation at 12, decrement each loop.
    {
        memcpy(&tmp, &buf[i], 2);
        printf("%x", tmp);

        tmp = rotate_right(tmp, r);

        memcpy(&buf[i], &tmp, 2);

        i += 2;

        memcpy(&tmp, &buf[i], 2);

        printf("%x\n", tmp);

        tmp = rotate_right(tmp, r);

        memcpy(&buf[i], &tmp, 2);


        i += 2;
    }

    printf("%s\n", buf); // Print the result.

    return 0;
}

