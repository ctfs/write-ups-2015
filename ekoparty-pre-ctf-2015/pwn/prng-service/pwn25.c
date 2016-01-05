#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <answer.h>

int main()
{

        signed int i;
        unsigned int base, try, rnd[128];

        printf("Welcome to PRNG service\nPlease wait while we generate 64 random numbers...\n");
        fflush(0);
        sleep(2);
        strcpy((char *)&rnd[0], ANSWER);
        srandom(1337);
        base = 64;
        for (i = 0; i < 64; i++) rnd[base + i] = random();
        printf("Process finished\n");
        fflush(0);
        try = 0;
        while (try < 10) {
                printf("Choose a number [0-63]?");
                fflush(0);

                scanf("%d", &i);
                fflush(0);

                if (i < 64) {
                        printf ("Your number is: 0x%08x\n", rnd[base + i]);
                } else {
                        printf("Index out of range\n");
                }
                try++;
                fflush(0);

        }
        printf ("Thank you for using our service\n");
        fflush(0);

        return 0;
}

