#include <stdio.h>
#include <string.h>

static char buf[1024];
static char response[1024];

void make_response() {
    snprintf(response, 0x400, buf);
}

void echo() {
    make_response();
    puts(response);
    fflush(stdin);
}

int main() {
    do {
        fgets(buf, 0x400, stdin);
        echo();
    } while(buf);
}
