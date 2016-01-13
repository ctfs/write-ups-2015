#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static uint32_t level = 0;
static void calc_level(const char *name);

int main() {
	char name[64] = "";

	setbuf(stdin, NULL);		// turn off buffered I/O
	setbuf(stdout, NULL);

	printf("What's your name? ");
	fgets(name, sizeof name, stdin);

	calc_level(name);

	usleep(150000);
	printf("Hello, ");
	printf(name);

	usleep(700000);
	if (level == 0xCCC31337) {
		FILE *f = fopen("flag.txt", "r");
		if (f) {
			char flag[80] = "";
			fread(flag, 1, sizeof flag, f);
			printf("The flag is: ");
			printf(flag);
			fclose(f);
		} else {
			printf("I would give you the flag, but I can't find it.\n");
		}
	} else {
		printf("Sorry, you're not leet enough to get the flag :(\n");
		usleep(400000);
		printf("Your hacker level is: 0x%x\n", level);
	}

	return 0;
}

static void calc_level(const char *name) {
	for (const char *p = name; *p; p++) {
		level *= 257;
		level ^= *p;
	}
	level %= 0xcafe;
}
