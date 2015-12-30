/* 
 * Rhinoxorus
 * CSAW CTF Quals 2015
 * Brandon Edwards, @drraid
*/

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 256

int sock_send(int sockfd, char *buf, size_t length);
void process_connection(int sockfd);
int tcp_server_loop(uint16_t port);
void reap_exited_processes(int sig_number);
unsigned char (*func_array[256])(unsigned char *buf, unsigned int count);
char password[BUF_SIZE];

int sock_send(int sockfd, char *buf, size_t length)
{
    ssize_t bytes_sent;
    size_t total_sent;
    bytes_sent = 0;
    total_sent = 0;
    
    while (total_sent < length)
    {
        bytes_sent = send(sockfd, buf+total_sent, length-(size_t )bytes_sent, 0);
        if (bytes_sent < 1)
        {
            break;
        }
        total_sent += (size_t )bytes_sent;
    }
    return length - total_sent;
}


unsigned char func_32(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x84];
    unsigned char byte=0x84;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_32, count is %u, bufsize is 0x84\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_33(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x88];
    unsigned char byte=0x88;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_33, count is %u, bufsize is 0x88\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_34(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8c];
    unsigned char byte=0x8c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_34, count is %u, bufsize is 0x8c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_35(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x90];
    unsigned char byte=0x90;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_35, count is %u, bufsize is 0x90\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_36(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x94];
    unsigned char byte=0x94;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_36, count is %u, bufsize is 0x94\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_37(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x98];
    unsigned char byte=0x98;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_37, count is %u, bufsize is 0x98\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_38(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x9c];
    unsigned char byte=0x9c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_38, count is %u, bufsize is 0x9c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_39(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa0];
    unsigned char byte=0xa0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_39, count is %u, bufsize is 0xa0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa4];
    unsigned char byte=0xa4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3a, count is %u, bufsize is 0xa4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa8];
    unsigned char byte=0xa8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3b, count is %u, bufsize is 0xa8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xac];
    unsigned char byte=0xac;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3c, count is %u, bufsize is 0xac\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb0];
    unsigned char byte=0xb0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3d, count is %u, bufsize is 0xb0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb4];
    unsigned char byte=0xb4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3e, count is %u, bufsize is 0xb4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_3f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb8];
    unsigned char byte=0xb8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_3f, count is %u, bufsize is 0xb8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_40(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xbc];
    unsigned char byte=0xbc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_40, count is %u, bufsize is 0xbc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_41(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc0];
    unsigned char byte=0xc0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_41, count is %u, bufsize is 0xc0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_42(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc4];
    unsigned char byte=0xc4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_42, count is %u, bufsize is 0xc4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_43(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc8];
    unsigned char byte=0xc8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_43, count is %u, bufsize is 0xc8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_44(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xcc];
    unsigned char byte=0xcc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_44, count is %u, bufsize is 0xcc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_45(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd0];
    unsigned char byte=0xd0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_45, count is %u, bufsize is 0xd0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_46(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd4];
    unsigned char byte=0xd4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_46, count is %u, bufsize is 0xd4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_47(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd8];
    unsigned char byte=0xd8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_47, count is %u, bufsize is 0xd8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_48(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xdc];
    unsigned char byte=0xdc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_48, count is %u, bufsize is 0xdc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_49(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe0];
    unsigned char byte=0xe0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_49, count is %u, bufsize is 0xe0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe4];
    unsigned char byte=0xe4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4a, count is %u, bufsize is 0xe4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe8];
    unsigned char byte=0xe8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4b, count is %u, bufsize is 0xe8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xec];
    unsigned char byte=0xec;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4c, count is %u, bufsize is 0xec\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf0];
    unsigned char byte=0xf0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4d, count is %u, bufsize is 0xf0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf4];
    unsigned char byte=0xf4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4e, count is %u, bufsize is 0xf4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_4f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf8];
    unsigned char byte=0xf8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_4f, count is %u, bufsize is 0xf8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_50(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xfc];
    unsigned char byte=0xfc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_50, count is %u, bufsize is 0xfc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_51(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x0];
    unsigned char byte=0x00;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_51, count is %u, bufsize is 0x00\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_52(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4];
    unsigned char byte=0x04;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_52, count is %u, bufsize is 0x04\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_53(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8];
    unsigned char byte=0x08;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_53, count is %u, bufsize is 0x08\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_54(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc];
    unsigned char byte=0x0c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_54, count is %u, bufsize is 0x0c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_55(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x10];
    unsigned char byte=0x10;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_55, count is %u, bufsize is 0x10\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_56(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x14];
    unsigned char byte=0x14;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_56, count is %u, bufsize is 0x14\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_57(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x18];
    unsigned char byte=0x18;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_57, count is %u, bufsize is 0x18\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_58(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x1c];
    unsigned char byte=0x1c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_58, count is %u, bufsize is 0x1c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_59(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x20];
    unsigned char byte=0x20;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_59, count is %u, bufsize is 0x20\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x24];
    unsigned char byte=0x24;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5a, count is %u, bufsize is 0x24\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x28];
    unsigned char byte=0x28;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5b, count is %u, bufsize is 0x28\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x2c];
    unsigned char byte=0x2c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5c, count is %u, bufsize is 0x2c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x30];
    unsigned char byte=0x30;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5d, count is %u, bufsize is 0x30\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x34];
    unsigned char byte=0x34;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5e, count is %u, bufsize is 0x34\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_5f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x38];
    unsigned char byte=0x38;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_5f, count is %u, bufsize is 0x38\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_60(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x3c];
    unsigned char byte=0x3c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_60, count is %u, bufsize is 0x3c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_61(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x40];
    unsigned char byte=0x40;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_61, count is %u, bufsize is 0x40\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_62(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x44];
    unsigned char byte=0x44;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_62, count is %u, bufsize is 0x44\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_63(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x48];
    unsigned char byte=0x48;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_63, count is %u, bufsize is 0x48\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_64(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4c];
    unsigned char byte=0x4c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_64, count is %u, bufsize is 0x4c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_65(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x50];
    unsigned char byte=0x50;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_65, count is %u, bufsize is 0x50\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_66(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x54];
    unsigned char byte=0x54;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_66, count is %u, bufsize is 0x54\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_67(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x58];
    unsigned char byte=0x58;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_67, count is %u, bufsize is 0x58\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_68(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x5c];
    unsigned char byte=0x5c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_68, count is %u, bufsize is 0x5c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_69(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x60];
    unsigned char byte=0x60;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_69, count is %u, bufsize is 0x60\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x64];
    unsigned char byte=0x64;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6a, count is %u, bufsize is 0x64\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x68];
    unsigned char byte=0x68;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6b, count is %u, bufsize is 0x68\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x6c];
    unsigned char byte=0x6c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6c, count is %u, bufsize is 0x6c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x70];
    unsigned char byte=0x70;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6d, count is %u, bufsize is 0x70\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x74];
    unsigned char byte=0x74;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6e, count is %u, bufsize is 0x74\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_6f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x78];
    unsigned char byte=0x78;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_6f, count is %u, bufsize is 0x78\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_70(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x7c];
    unsigned char byte=0x7c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_70, count is %u, bufsize is 0x7c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_71(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x80];
    unsigned char byte=0x80;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_71, count is %u, bufsize is 0x80\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_72(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x84];
    unsigned char byte=0x84;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_72, count is %u, bufsize is 0x84\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_73(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x88];
    unsigned char byte=0x88;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_73, count is %u, bufsize is 0x88\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_74(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8c];
    unsigned char byte=0x8c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_74, count is %u, bufsize is 0x8c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_75(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x90];
    unsigned char byte=0x90;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_75, count is %u, bufsize is 0x90\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_76(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x94];
    unsigned char byte=0x94;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_76, count is %u, bufsize is 0x94\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_77(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x98];
    unsigned char byte=0x98;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_77, count is %u, bufsize is 0x98\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_78(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x9c];
    unsigned char byte=0x9c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_78, count is %u, bufsize is 0x9c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_79(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa0];
    unsigned char byte=0xa0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_79, count is %u, bufsize is 0xa0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa4];
    unsigned char byte=0xa4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7a, count is %u, bufsize is 0xa4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa8];
    unsigned char byte=0xa8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7b, count is %u, bufsize is 0xa8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xac];
    unsigned char byte=0xac;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7c, count is %u, bufsize is 0xac\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb0];
    unsigned char byte=0xb0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7d, count is %u, bufsize is 0xb0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb4];
    unsigned char byte=0xb4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7e, count is %u, bufsize is 0xb4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_7f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb8];
    unsigned char byte=0xb8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_7f, count is %u, bufsize is 0xb8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_80(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xbc];
    unsigned char byte=0xbc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_80, count is %u, bufsize is 0xbc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_81(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc0];
    unsigned char byte=0xc0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_81, count is %u, bufsize is 0xc0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_82(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc4];
    unsigned char byte=0xc4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_82, count is %u, bufsize is 0xc4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_83(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc8];
    unsigned char byte=0xc8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_83, count is %u, bufsize is 0xc8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_84(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xcc];
    unsigned char byte=0xcc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_84, count is %u, bufsize is 0xcc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_85(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd0];
    unsigned char byte=0xd0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_85, count is %u, bufsize is 0xd0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_86(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd4];
    unsigned char byte=0xd4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_86, count is %u, bufsize is 0xd4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_87(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd8];
    unsigned char byte=0xd8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_87, count is %u, bufsize is 0xd8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_88(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xdc];
    unsigned char byte=0xdc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_88, count is %u, bufsize is 0xdc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_89(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe0];
    unsigned char byte=0xe0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_89, count is %u, bufsize is 0xe0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe4];
    unsigned char byte=0xe4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8a, count is %u, bufsize is 0xe4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe8];
    unsigned char byte=0xe8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8b, count is %u, bufsize is 0xe8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xec];
    unsigned char byte=0xec;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8c, count is %u, bufsize is 0xec\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf0];
    unsigned char byte=0xf0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8d, count is %u, bufsize is 0xf0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf4];
    unsigned char byte=0xf4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8e, count is %u, bufsize is 0xf4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_8f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf8];
    unsigned char byte=0xf8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_8f, count is %u, bufsize is 0xf8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_90(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xfc];
    unsigned char byte=0xfc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_90, count is %u, bufsize is 0xfc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_91(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x0];
    unsigned char byte=0x00;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_91, count is %u, bufsize is 0x00\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_92(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4];
    unsigned char byte=0x04;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_92, count is %u, bufsize is 0x04\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_93(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8];
    unsigned char byte=0x08;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_93, count is %u, bufsize is 0x08\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_94(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc];
    unsigned char byte=0x0c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_94, count is %u, bufsize is 0x0c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_95(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x10];
    unsigned char byte=0x10;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_95, count is %u, bufsize is 0x10\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_96(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x14];
    unsigned char byte=0x14;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_96, count is %u, bufsize is 0x14\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_97(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x18];
    unsigned char byte=0x18;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_97, count is %u, bufsize is 0x18\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_98(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x1c];
    unsigned char byte=0x1c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_98, count is %u, bufsize is 0x1c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_99(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x20];
    unsigned char byte=0x20;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_99, count is %u, bufsize is 0x20\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x24];
    unsigned char byte=0x24;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9a, count is %u, bufsize is 0x24\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x28];
    unsigned char byte=0x28;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9b, count is %u, bufsize is 0x28\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x2c];
    unsigned char byte=0x2c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9c, count is %u, bufsize is 0x2c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x30];
    unsigned char byte=0x30;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9d, count is %u, bufsize is 0x30\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x34];
    unsigned char byte=0x34;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9e, count is %u, bufsize is 0x34\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_9f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x38];
    unsigned char byte=0x38;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_9f, count is %u, bufsize is 0x38\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x3c];
    unsigned char byte=0x3c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a0, count is %u, bufsize is 0x3c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x40];
    unsigned char byte=0x40;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a1, count is %u, bufsize is 0x40\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x44];
    unsigned char byte=0x44;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a2, count is %u, bufsize is 0x44\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x48];
    unsigned char byte=0x48;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a3, count is %u, bufsize is 0x48\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4c];
    unsigned char byte=0x4c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a4, count is %u, bufsize is 0x4c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x50];
    unsigned char byte=0x50;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a5, count is %u, bufsize is 0x50\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x54];
    unsigned char byte=0x54;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a6, count is %u, bufsize is 0x54\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x58];
    unsigned char byte=0x58;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a7, count is %u, bufsize is 0x58\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x5c];
    unsigned char byte=0x5c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a8, count is %u, bufsize is 0x5c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_a9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x60];
    unsigned char byte=0x60;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_a9, count is %u, bufsize is 0x60\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_aa(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x64];
    unsigned char byte=0x64;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_aa, count is %u, bufsize is 0x64\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ab(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x68];
    unsigned char byte=0x68;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ab, count is %u, bufsize is 0x68\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ac(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x6c];
    unsigned char byte=0x6c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ac, count is %u, bufsize is 0x6c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ad(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x70];
    unsigned char byte=0x70;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ad, count is %u, bufsize is 0x70\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ae(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x74];
    unsigned char byte=0x74;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ae, count is %u, bufsize is 0x74\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_af(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x78];
    unsigned char byte=0x78;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_af, count is %u, bufsize is 0x78\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x7c];
    unsigned char byte=0x7c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b0, count is %u, bufsize is 0x7c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x80];
    unsigned char byte=0x80;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b1, count is %u, bufsize is 0x80\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x84];
    unsigned char byte=0x84;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b2, count is %u, bufsize is 0x84\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x88];
    unsigned char byte=0x88;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b3, count is %u, bufsize is 0x88\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8c];
    unsigned char byte=0x8c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b4, count is %u, bufsize is 0x8c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x90];
    unsigned char byte=0x90;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b5, count is %u, bufsize is 0x90\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x94];
    unsigned char byte=0x94;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b6, count is %u, bufsize is 0x94\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x98];
    unsigned char byte=0x98;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b7, count is %u, bufsize is 0x98\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x9c];
    unsigned char byte=0x9c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b8, count is %u, bufsize is 0x9c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_b9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa0];
    unsigned char byte=0xa0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_b9, count is %u, bufsize is 0xa0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ba(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa4];
    unsigned char byte=0xa4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ba, count is %u, bufsize is 0xa4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_bb(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa8];
    unsigned char byte=0xa8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_bb, count is %u, bufsize is 0xa8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_bc(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xac];
    unsigned char byte=0xac;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_bc, count is %u, bufsize is 0xac\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_bd(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb0];
    unsigned char byte=0xb0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_bd, count is %u, bufsize is 0xb0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_be(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb4];
    unsigned char byte=0xb4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_be, count is %u, bufsize is 0xb4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_bf(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb8];
    unsigned char byte=0xb8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_bf, count is %u, bufsize is 0xb8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xbc];
    unsigned char byte=0xbc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c0, count is %u, bufsize is 0xbc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc0];
    unsigned char byte=0xc0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c1, count is %u, bufsize is 0xc0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc4];
    unsigned char byte=0xc4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c2, count is %u, bufsize is 0xc4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc8];
    unsigned char byte=0xc8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c3, count is %u, bufsize is 0xc8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xcc];
    unsigned char byte=0xcc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c4, count is %u, bufsize is 0xcc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd0];
    unsigned char byte=0xd0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c5, count is %u, bufsize is 0xd0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd4];
    unsigned char byte=0xd4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c6, count is %u, bufsize is 0xd4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd8];
    unsigned char byte=0xd8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c7, count is %u, bufsize is 0xd8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xdc];
    unsigned char byte=0xdc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c8, count is %u, bufsize is 0xdc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_c9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe0];
    unsigned char byte=0xe0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_c9, count is %u, bufsize is 0xe0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ca(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe4];
    unsigned char byte=0xe4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ca, count is %u, bufsize is 0xe4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_cb(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe8];
    unsigned char byte=0xe8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_cb, count is %u, bufsize is 0xe8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_cc(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xec];
    unsigned char byte=0xec;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_cc, count is %u, bufsize is 0xec\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_cd(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf0];
    unsigned char byte=0xf0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_cd, count is %u, bufsize is 0xf0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ce(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf4];
    unsigned char byte=0xf4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ce, count is %u, bufsize is 0xf4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_cf(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf8];
    unsigned char byte=0xf8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_cf, count is %u, bufsize is 0xf8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xfc];
    unsigned char byte=0xfc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d0, count is %u, bufsize is 0xfc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x0];
    unsigned char byte=0x00;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d1, count is %u, bufsize is 0x00\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4];
    unsigned char byte=0x04;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d2, count is %u, bufsize is 0x04\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8];
    unsigned char byte=0x08;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d3, count is %u, bufsize is 0x08\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc];
    unsigned char byte=0x0c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d4, count is %u, bufsize is 0x0c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x10];
    unsigned char byte=0x10;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d5, count is %u, bufsize is 0x10\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x14];
    unsigned char byte=0x14;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d6, count is %u, bufsize is 0x14\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x18];
    unsigned char byte=0x18;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d7, count is %u, bufsize is 0x18\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x1c];
    unsigned char byte=0x1c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d8, count is %u, bufsize is 0x1c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_d9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x20];
    unsigned char byte=0x20;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_d9, count is %u, bufsize is 0x20\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_da(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x24];
    unsigned char byte=0x24;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_da, count is %u, bufsize is 0x24\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_db(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x28];
    unsigned char byte=0x28;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_db, count is %u, bufsize is 0x28\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_dc(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x2c];
    unsigned char byte=0x2c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_dc, count is %u, bufsize is 0x2c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_dd(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x30];
    unsigned char byte=0x30;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_dd, count is %u, bufsize is 0x30\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_de(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x34];
    unsigned char byte=0x34;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_de, count is %u, bufsize is 0x34\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_df(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x38];
    unsigned char byte=0x38;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_df, count is %u, bufsize is 0x38\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x3c];
    unsigned char byte=0x3c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e0, count is %u, bufsize is 0x3c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x40];
    unsigned char byte=0x40;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e1, count is %u, bufsize is 0x40\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x44];
    unsigned char byte=0x44;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e2, count is %u, bufsize is 0x44\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x48];
    unsigned char byte=0x48;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e3, count is %u, bufsize is 0x48\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4c];
    unsigned char byte=0x4c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e4, count is %u, bufsize is 0x4c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x50];
    unsigned char byte=0x50;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e5, count is %u, bufsize is 0x50\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x54];
    unsigned char byte=0x54;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e6, count is %u, bufsize is 0x54\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x58];
    unsigned char byte=0x58;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e7, count is %u, bufsize is 0x58\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x5c];
    unsigned char byte=0x5c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e8, count is %u, bufsize is 0x5c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_e9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x60];
    unsigned char byte=0x60;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_e9, count is %u, bufsize is 0x60\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ea(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x64];
    unsigned char byte=0x64;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ea, count is %u, bufsize is 0x64\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_eb(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x68];
    unsigned char byte=0x68;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_eb, count is %u, bufsize is 0x68\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ec(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x6c];
    unsigned char byte=0x6c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ec, count is %u, bufsize is 0x6c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ed(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x70];
    unsigned char byte=0x70;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ed, count is %u, bufsize is 0x70\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ee(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x74];
    unsigned char byte=0x74;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ee, count is %u, bufsize is 0x74\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ef(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x78];
    unsigned char byte=0x78;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ef, count is %u, bufsize is 0x78\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f0(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x7c];
    unsigned char byte=0x7c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f0, count is %u, bufsize is 0x7c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f1(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x80];
    unsigned char byte=0x80;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f1, count is %u, bufsize is 0x80\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f2(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x84];
    unsigned char byte=0x84;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f2, count is %u, bufsize is 0x84\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f3(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x88];
    unsigned char byte=0x88;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f3, count is %u, bufsize is 0x88\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f4(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8c];
    unsigned char byte=0x8c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f4, count is %u, bufsize is 0x8c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f5(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x90];
    unsigned char byte=0x90;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f5, count is %u, bufsize is 0x90\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f6(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x94];
    unsigned char byte=0x94;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f6, count is %u, bufsize is 0x94\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f7(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x98];
    unsigned char byte=0x98;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f7, count is %u, bufsize is 0x98\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f8(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x9c];
    unsigned char byte=0x9c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f8, count is %u, bufsize is 0x9c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_f9(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa0];
    unsigned char byte=0xa0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_f9, count is %u, bufsize is 0xa0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_fa(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa4];
    unsigned char byte=0xa4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_fa, count is %u, bufsize is 0xa4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_fb(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xa8];
    unsigned char byte=0xa8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_fb, count is %u, bufsize is 0xa8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_fc(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xac];
    unsigned char byte=0xac;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_fc, count is %u, bufsize is 0xac\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_fd(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb0];
    unsigned char byte=0xb0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_fd, count is %u, bufsize is 0xb0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_fe(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb4];
    unsigned char byte=0xb4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_fe, count is %u, bufsize is 0xb4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_ff(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xb8];
    unsigned char byte=0xb8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_ff, count is %u, bufsize is 0xb8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_00(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xbc];
    unsigned char byte=0xbc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_00, count is %u, bufsize is 0xbc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_01(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc0];
    unsigned char byte=0xc0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_01, count is %u, bufsize is 0xc0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_02(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc4];
    unsigned char byte=0xc4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_02, count is %u, bufsize is 0xc4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_03(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc8];
    unsigned char byte=0xc8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_03, count is %u, bufsize is 0xc8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_04(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xcc];
    unsigned char byte=0xcc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_04, count is %u, bufsize is 0xcc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_05(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd0];
    unsigned char byte=0xd0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_05, count is %u, bufsize is 0xd0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_06(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd4];
    unsigned char byte=0xd4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_06, count is %u, bufsize is 0xd4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_07(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xd8];
    unsigned char byte=0xd8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_07, count is %u, bufsize is 0xd8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_08(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xdc];
    unsigned char byte=0xdc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_08, count is %u, bufsize is 0xdc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_09(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe0];
    unsigned char byte=0xe0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_09, count is %u, bufsize is 0xe0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe4];
    unsigned char byte=0xe4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0a, count is %u, bufsize is 0xe4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xe8];
    unsigned char byte=0xe8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0b, count is %u, bufsize is 0xe8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xec];
    unsigned char byte=0xec;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0c, count is %u, bufsize is 0xec\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf0];
    unsigned char byte=0xf0;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0d, count is %u, bufsize is 0xf0\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf4];
    unsigned char byte=0xf4;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0e, count is %u, bufsize is 0xf4\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_0f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xf8];
    unsigned char byte=0xf8;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_0f, count is %u, bufsize is 0xf8\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_10(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xfc];
    unsigned char byte=0xfc;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_10, count is %u, bufsize is 0xfc\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_11(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x0];
    unsigned char byte=0x00;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_11, count is %u, bufsize is 0x00\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_12(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4];
    unsigned char byte=0x04;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_12, count is %u, bufsize is 0x04\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_13(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x8];
    unsigned char byte=0x08;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_13, count is %u, bufsize is 0x08\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_14(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0xc];
    unsigned char byte=0x0c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_14, count is %u, bufsize is 0x0c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_15(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x10];
    unsigned char byte=0x10;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_15, count is %u, bufsize is 0x10\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_16(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x14];
    unsigned char byte=0x14;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_16, count is %u, bufsize is 0x14\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_17(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x18];
    unsigned char byte=0x18;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_17, count is %u, bufsize is 0x18\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_18(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x1c];
    unsigned char byte=0x1c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_18, count is %u, bufsize is 0x1c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_19(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x20];
    unsigned char byte=0x20;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_19, count is %u, bufsize is 0x20\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x24];
    unsigned char byte=0x24;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1a, count is %u, bufsize is 0x24\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x28];
    unsigned char byte=0x28;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1b, count is %u, bufsize is 0x28\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x2c];
    unsigned char byte=0x2c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1c, count is %u, bufsize is 0x2c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x30];
    unsigned char byte=0x30;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1d, count is %u, bufsize is 0x30\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x34];
    unsigned char byte=0x34;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1e, count is %u, bufsize is 0x34\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_1f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x38];
    unsigned char byte=0x38;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_1f, count is %u, bufsize is 0x38\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_20(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x3c];
    unsigned char byte=0x3c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_20, count is %u, bufsize is 0x3c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_21(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x40];
    unsigned char byte=0x40;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_21, count is %u, bufsize is 0x40\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_22(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x44];
    unsigned char byte=0x44;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_22, count is %u, bufsize is 0x44\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_23(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x48];
    unsigned char byte=0x48;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_23, count is %u, bufsize is 0x48\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_24(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x4c];
    unsigned char byte=0x4c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_24, count is %u, bufsize is 0x4c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_25(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x50];
    unsigned char byte=0x50;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_25, count is %u, bufsize is 0x50\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_26(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x54];
    unsigned char byte=0x54;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_26, count is %u, bufsize is 0x54\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_27(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x58];
    unsigned char byte=0x58;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_27, count is %u, bufsize is 0x58\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_28(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x5c];
    unsigned char byte=0x5c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_28, count is %u, bufsize is 0x5c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_29(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x60];
    unsigned char byte=0x60;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_29, count is %u, bufsize is 0x60\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2a(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x64];
    unsigned char byte=0x64;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2a, count is %u, bufsize is 0x64\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2b(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x68];
    unsigned char byte=0x68;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2b, count is %u, bufsize is 0x68\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2c(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x6c];
    unsigned char byte=0x6c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2c, count is %u, bufsize is 0x6c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2d(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x70];
    unsigned char byte=0x70;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2d, count is %u, bufsize is 0x70\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2e(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x74];
    unsigned char byte=0x74;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2e, count is %u, bufsize is 0x74\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_2f(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x78];
    unsigned char byte=0x78;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_2f, count is %u, bufsize is 0x78\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_30(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x7c];
    unsigned char byte=0x7c;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_30, count is %u, bufsize is 0x7c\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

unsigned char func_31(unsigned char *buf, unsigned int count)
{
    unsigned int i;
    unsigned char localbuf[0x80];
    unsigned char byte=0x80;
    memset(localbuf, byte, sizeof(localbuf));
    printf("in function func_31, count is %u, bufsize is 0x80\n", count);
    if (0 == --count)
    {
         return 0;
    }
    for (i = 0; i < count; ++i)
    {
         localbuf[i] ^= buf[i];
    }
    func_array[localbuf[0]](localbuf+1, count);
    return 0;
}

/*
func[0x00] = func_0x32  byte/buf 0x84
func[0x01] = func_0x33  byte/buf 0x88
func[0x02] = func_0x34  byte/buf 0x8c
func[0x03] = func_0x35  byte/buf 0x90
func[0x04] = func_0x36  byte/buf 0x94
func[0x05] = func_0x37  byte/buf 0x98
func[0x06] = func_0x38  byte/buf 0x9c
func[0x07] = func_0x39  byte/buf 0xa0
func[0x08] = func_0x3a  byte/buf 0xa4
func[0x09] = func_0x3b  byte/buf 0xa8
func[0x0a] = func_0x3c  byte/buf 0xac
func[0x0b] = func_0x3d  byte/buf 0xb0
func[0x0c] = func_0x3e  byte/buf 0xb4
func[0x0d] = func_0x3f  byte/buf 0xb8
func[0x0e] = func_0x40  byte/buf 0xbc
func[0x0f] = func_0x41  byte/buf 0xc0
func[0x10] = func_0x42  byte/buf 0xc4
func[0x11] = func_0x43  byte/buf 0xc8
func[0x12] = func_0x44  byte/buf 0xcc
func[0x13] = func_0x45  byte/buf 0xd0
func[0x14] = func_0x46  byte/buf 0xd4
func[0x15] = func_0x47  byte/buf 0xd8
func[0x16] = func_0x48  byte/buf 0xdc
func[0x17] = func_0x49  byte/buf 0xe0
func[0x18] = func_0x4a  byte/buf 0xe4
func[0x19] = func_0x4b  byte/buf 0xe8
func[0x1a] = func_0x4c  byte/buf 0xec
func[0x1b] = func_0x4d  byte/buf 0xf0
func[0x1c] = func_0x4e  byte/buf 0xf4
func[0x1d] = func_0x4f  byte/buf 0xf8
func[0x1e] = func_0x50  byte/buf 0xfc
func[0x1f] = func_0x51  byte/buf 0x00
func[0x20] = func_0x52  byte/buf 0x04
func[0x21] = func_0x53  byte/buf 0x08
func[0x22] = func_0x54  byte/buf 0x0c
func[0x23] = func_0x55  byte/buf 0x10
func[0x24] = func_0x56  byte/buf 0x14
func[0x25] = func_0x57  byte/buf 0x18
func[0x26] = func_0x58  byte/buf 0x1c
func[0x27] = func_0x59  byte/buf 0x20
func[0x28] = func_0x5a  byte/buf 0x24
func[0x29] = func_0x5b  byte/buf 0x28
func[0x2a] = func_0x5c  byte/buf 0x2c
func[0x2b] = func_0x5d  byte/buf 0x30
func[0x2c] = func_0x5e  byte/buf 0x34
func[0x2d] = func_0x5f  byte/buf 0x38
func[0x2e] = func_0x60  byte/buf 0x3c
func[0x2f] = func_0x61  byte/buf 0x40
func[0x30] = func_0x62  byte/buf 0x44
func[0x31] = func_0x63  byte/buf 0x48
func[0x32] = func_0x64  byte/buf 0x4c
func[0x33] = func_0x65  byte/buf 0x50
func[0x34] = func_0x66  byte/buf 0x54
func[0x35] = func_0x67  byte/buf 0x58
func[0x36] = func_0x68  byte/buf 0x5c
func[0x37] = func_0x69  byte/buf 0x60
func[0x38] = func_0x6a  byte/buf 0x64
func[0x39] = func_0x6b  byte/buf 0x68
func[0x3a] = func_0x6c  byte/buf 0x6c
func[0x3b] = func_0x6d  byte/buf 0x70
func[0x3c] = func_0x6e  byte/buf 0x74
func[0x3d] = func_0x6f  byte/buf 0x78
func[0x3e] = func_0x70  byte/buf 0x7c
func[0x3f] = func_0x71  byte/buf 0x80
func[0x40] = func_0x72  byte/buf 0x84
func[0x41] = func_0x73  byte/buf 0x88
func[0x42] = func_0x74  byte/buf 0x8c
func[0x43] = func_0x75  byte/buf 0x90
func[0x44] = func_0x76  byte/buf 0x94
func[0x45] = func_0x77  byte/buf 0x98
func[0x46] = func_0x78  byte/buf 0x9c
func[0x47] = func_0x79  byte/buf 0xa0
func[0x48] = func_0x7a  byte/buf 0xa4
func[0x49] = func_0x7b  byte/buf 0xa8
func[0x4a] = func_0x7c  byte/buf 0xac
func[0x4b] = func_0x7d  byte/buf 0xb0
func[0x4c] = func_0x7e  byte/buf 0xb4
func[0x4d] = func_0x7f  byte/buf 0xb8
func[0x4e] = func_0x80  byte/buf 0xbc
func[0x4f] = func_0x81  byte/buf 0xc0
func[0x50] = func_0x82  byte/buf 0xc4
func[0x51] = func_0x83  byte/buf 0xc8
func[0x52] = func_0x84  byte/buf 0xcc
func[0x53] = func_0x85  byte/buf 0xd0
func[0x54] = func_0x86  byte/buf 0xd4
func[0x55] = func_0x87  byte/buf 0xd8
func[0x56] = func_0x88  byte/buf 0xdc
func[0x57] = func_0x89  byte/buf 0xe0
func[0x58] = func_0x8a  byte/buf 0xe4
func[0x59] = func_0x8b  byte/buf 0xe8
func[0x5a] = func_0x8c  byte/buf 0xec
func[0x5b] = func_0x8d  byte/buf 0xf0
func[0x5c] = func_0x8e  byte/buf 0xf4
func[0x5d] = func_0x8f  byte/buf 0xf8
func[0x5e] = func_0x90  byte/buf 0xfc
func[0x5f] = func_0x91  byte/buf 0x00
func[0x60] = func_0x92  byte/buf 0x04
func[0x61] = func_0x93  byte/buf 0x08
func[0x62] = func_0x94  byte/buf 0x0c
func[0x63] = func_0x95  byte/buf 0x10
func[0x64] = func_0x96  byte/buf 0x14
func[0x65] = func_0x97  byte/buf 0x18
func[0x66] = func_0x98  byte/buf 0x1c
func[0x67] = func_0x99  byte/buf 0x20
func[0x68] = func_0x9a  byte/buf 0x24
func[0x69] = func_0x9b  byte/buf 0x28
func[0x6a] = func_0x9c  byte/buf 0x2c
func[0x6b] = func_0x9d  byte/buf 0x30
func[0x6c] = func_0x9e  byte/buf 0x34
func[0x6d] = func_0x9f  byte/buf 0x38
func[0x6e] = func_0xa0  byte/buf 0x3c
func[0x6f] = func_0xa1  byte/buf 0x40
func[0x70] = func_0xa2  byte/buf 0x44
func[0x71] = func_0xa3  byte/buf 0x48
func[0x72] = func_0xa4  byte/buf 0x4c
func[0x73] = func_0xa5  byte/buf 0x50
func[0x74] = func_0xa6  byte/buf 0x54
func[0x75] = func_0xa7  byte/buf 0x58
func[0x76] = func_0xa8  byte/buf 0x5c
func[0x77] = func_0xa9  byte/buf 0x60
func[0x78] = func_0xaa  byte/buf 0x64
func[0x79] = func_0xab  byte/buf 0x68
func[0x7a] = func_0xac  byte/buf 0x6c
func[0x7b] = func_0xad  byte/buf 0x70
func[0x7c] = func_0xae  byte/buf 0x74
func[0x7d] = func_0xaf  byte/buf 0x78
func[0x7e] = func_0xb0  byte/buf 0x7c
func[0x7f] = func_0xb1  byte/buf 0x80
func[0x80] = func_0xb2  byte/buf 0x84
func[0x81] = func_0xb3  byte/buf 0x88
func[0x82] = func_0xb4  byte/buf 0x8c
func[0x83] = func_0xb5  byte/buf 0x90
func[0x84] = func_0xb6  byte/buf 0x94
func[0x85] = func_0xb7  byte/buf 0x98
func[0x86] = func_0xb8  byte/buf 0x9c
func[0x87] = func_0xb9  byte/buf 0xa0
func[0x88] = func_0xba  byte/buf 0xa4
func[0x89] = func_0xbb  byte/buf 0xa8
func[0x8a] = func_0xbc  byte/buf 0xac
func[0x8b] = func_0xbd  byte/buf 0xb0
func[0x8c] = func_0xbe  byte/buf 0xb4
func[0x8d] = func_0xbf  byte/buf 0xb8
func[0x8e] = func_0xc0  byte/buf 0xbc
func[0x8f] = func_0xc1  byte/buf 0xc0
func[0x90] = func_0xc2  byte/buf 0xc4
func[0x91] = func_0xc3  byte/buf 0xc8
func[0x92] = func_0xc4  byte/buf 0xcc
func[0x93] = func_0xc5  byte/buf 0xd0
func[0x94] = func_0xc6  byte/buf 0xd4
func[0x95] = func_0xc7  byte/buf 0xd8
func[0x96] = func_0xc8  byte/buf 0xdc
func[0x97] = func_0xc9  byte/buf 0xe0
func[0x98] = func_0xca  byte/buf 0xe4
func[0x99] = func_0xcb  byte/buf 0xe8
func[0x9a] = func_0xcc  byte/buf 0xec
func[0x9b] = func_0xcd  byte/buf 0xf0
func[0x9c] = func_0xce  byte/buf 0xf4
func[0x9d] = func_0xcf  byte/buf 0xf8
func[0x9e] = func_0xd0  byte/buf 0xfc
func[0x9f] = func_0xd1  byte/buf 0x00
func[0xa0] = func_0xd2  byte/buf 0x04
func[0xa1] = func_0xd3  byte/buf 0x08
func[0xa2] = func_0xd4  byte/buf 0x0c
func[0xa3] = func_0xd5  byte/buf 0x10
func[0xa4] = func_0xd6  byte/buf 0x14
func[0xa5] = func_0xd7  byte/buf 0x18
func[0xa6] = func_0xd8  byte/buf 0x1c
func[0xa7] = func_0xd9  byte/buf 0x20
func[0xa8] = func_0xda  byte/buf 0x24
func[0xa9] = func_0xdb  byte/buf 0x28
func[0xaa] = func_0xdc  byte/buf 0x2c
func[0xab] = func_0xdd  byte/buf 0x30
func[0xac] = func_0xde  byte/buf 0x34
func[0xad] = func_0xdf  byte/buf 0x38
func[0xae] = func_0xe0  byte/buf 0x3c
func[0xaf] = func_0xe1  byte/buf 0x40
func[0xb0] = func_0xe2  byte/buf 0x44
func[0xb1] = func_0xe3  byte/buf 0x48
func[0xb2] = func_0xe4  byte/buf 0x4c
func[0xb3] = func_0xe5  byte/buf 0x50
func[0xb4] = func_0xe6  byte/buf 0x54
func[0xb5] = func_0xe7  byte/buf 0x58
func[0xb6] = func_0xe8  byte/buf 0x5c
func[0xb7] = func_0xe9  byte/buf 0x60
func[0xb8] = func_0xea  byte/buf 0x64
func[0xb9] = func_0xeb  byte/buf 0x68
func[0xba] = func_0xec  byte/buf 0x6c
func[0xbb] = func_0xed  byte/buf 0x70
func[0xbc] = func_0xee  byte/buf 0x74
func[0xbd] = func_0xef  byte/buf 0x78
func[0xbe] = func_0xf0  byte/buf 0x7c
func[0xbf] = func_0xf1  byte/buf 0x80
func[0xc0] = func_0xf2  byte/buf 0x84
func[0xc1] = func_0xf3  byte/buf 0x88
func[0xc2] = func_0xf4  byte/buf 0x8c
func[0xc3] = func_0xf5  byte/buf 0x90
func[0xc4] = func_0xf6  byte/buf 0x94
func[0xc5] = func_0xf7  byte/buf 0x98
func[0xc6] = func_0xf8  byte/buf 0x9c
func[0xc7] = func_0xf9  byte/buf 0xa0
func[0xc8] = func_0xfa  byte/buf 0xa4
func[0xc9] = func_0xfb  byte/buf 0xa8
func[0xca] = func_0xfc  byte/buf 0xac
func[0xcb] = func_0xfd  byte/buf 0xb0
func[0xcc] = func_0xfe  byte/buf 0xb4
func[0xcd] = func_0xff  byte/buf 0xb8
func[0xce] = func_0x00  byte/buf 0xbc
func[0xcf] = func_0x01  byte/buf 0xc0
func[0xd0] = func_0x02  byte/buf 0xc4
func[0xd1] = func_0x03  byte/buf 0xc8
func[0xd2] = func_0x04  byte/buf 0xcc
func[0xd3] = func_0x05  byte/buf 0xd0
func[0xd4] = func_0x06  byte/buf 0xd4
func[0xd5] = func_0x07  byte/buf 0xd8
func[0xd6] = func_0x08  byte/buf 0xdc
func[0xd7] = func_0x09  byte/buf 0xe0
func[0xd8] = func_0x0a  byte/buf 0xe4
func[0xd9] = func_0x0b  byte/buf 0xe8
func[0xda] = func_0x0c  byte/buf 0xec
func[0xdb] = func_0x0d  byte/buf 0xf0
func[0xdc] = func_0x0e  byte/buf 0xf4
func[0xdd] = func_0x0f  byte/buf 0xf8
func[0xde] = func_0x10  byte/buf 0xfc
func[0xdf] = func_0x11  byte/buf 0x00
func[0xe0] = func_0x12  byte/buf 0x04
func[0xe1] = func_0x13  byte/buf 0x08
func[0xe2] = func_0x14  byte/buf 0x0c
func[0xe3] = func_0x15  byte/buf 0x10
func[0xe4] = func_0x16  byte/buf 0x14
func[0xe5] = func_0x17  byte/buf 0x18
func[0xe6] = func_0x18  byte/buf 0x1c
func[0xe7] = func_0x19  byte/buf 0x20
func[0xe8] = func_0x1a  byte/buf 0x24
func[0xe9] = func_0x1b  byte/buf 0x28
func[0xea] = func_0x1c  byte/buf 0x2c
func[0xeb] = func_0x1d  byte/buf 0x30
func[0xec] = func_0x1e  byte/buf 0x34
func[0xed] = func_0x1f  byte/buf 0x38
func[0xee] = func_0x20  byte/buf 0x3c
func[0xef] = func_0x21  byte/buf 0x40
func[0xf0] = func_0x22  byte/buf 0x44
func[0xf1] = func_0x23  byte/buf 0x48
func[0xf2] = func_0x24  byte/buf 0x4c
func[0xf3] = func_0x25  byte/buf 0x50
func[0xf4] = func_0x26  byte/buf 0x54
func[0xf5] = func_0x27  byte/buf 0x58
func[0xf6] = func_0x28  byte/buf 0x5c
func[0xf7] = func_0x29  byte/buf 0x60
func[0xf8] = func_0x2a  byte/buf 0x64
func[0xf9] = func_0x2b  byte/buf 0x68
func[0xfa] = func_0x2c  byte/buf 0x6c
func[0xfb] = func_0x2d  byte/buf 0x70
func[0xfc] = func_0x2e  byte/buf 0x74
func[0xfd] = func_0x2f  byte/buf 0x78
func[0xfe] = func_0x30  byte/buf 0x7c
func[0xff] = func_0x31  byte/buf 0x80

*/

void process_connection(int sockfd)
{
    ssize_t bytes_read;
    unsigned char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, sizeof(recv_buf));
    bytes_read = recv(sockfd, recv_buf, (unsigned int )BUF_SIZE, 0);
    if (bytes_read > 0)
    {
        func_array[recv_buf[0]](recv_buf, (unsigned int)bytes_read);
    }
    return;
}

void reap_exited_processes(int sig_number)
{
    pid_t process_id;
    while (1)
    {
        process_id = waitpid(-1, NULL, WNOHANG);
        if ((0==process_id) || (-1==process_id))
        {
            break;
        }
    }
    return;
}

int tcp_server_loop(uint16_t port)
{
    int sd;
    int client_sd;
    struct sockaddr_in server; 
    struct sockaddr_in client;
    socklen_t address_len;

    pid_t process_id;
    struct sigaction sig_manager;
    
    memset(&server, 0, sizeof(server)); 
    memset(&client, 0, sizeof(client));

    sig_manager.sa_handler = reap_exited_processes;
    sig_manager.sa_flags = SA_RESTART;
    
    if (-1 == sigfillset(&sig_manager.sa_mask))
    {
        printf("[Rhinoxorus] Error: sigfillset failed\n");
        return -1;
    }

    if (-1 == sigaction(SIGCHLD, &sig_manager, NULL))
    {
        printf("[Rhinoxorus] Error: sigaction failed\n");
        return -1;
    }

    sd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sd < 0)
    {
        printf("[Rhinoxorus] Error: failed to acquire socket\n");
        return -1;
    }

    address_len = sizeof(struct sockaddr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (-1 == bind(sd, (struct sockaddr *)&server, address_len))
    {
        printf("[Rhinoxorus] Error: failed to bind on 0.0.0.0:%i\n", port);
        return -1;
    }

    if (-1 == listen(sd, SOMAXCONN))
    {
        printf("[Rhinoxorus] Error: failed to listen on socket\n");
        return -1;
    }

    printf("[Rhinoxorus] Entering main listening loop...\n");
    while (1)
    {
        client_sd = accept(sd, (struct sockaddr *)&client, &address_len);
        if (-1 == client_sd)
        {
            printf("[Rhinoxorus] Error: failed accepting connection, continuing\n");
            continue;
        }

        printf("[Rhinoxorus] Accepted connection from %s\n", inet_ntoa(client.sin_addr)); 
        
        process_id = fork();
        if (0 == process_id)
        {
            process_connection(client_sd);
            close(client_sd); 
            close(sd);
            exit(0);
        }

        close(client_sd);
    }
}

int main(int argc, char *argv[])
{
    FILE *fd; 
    char *newline;

    func_array[0]=func_32;
    func_array[1]=func_33;
    func_array[2]=func_34;
    func_array[3]=func_35;
    func_array[4]=func_36;
    func_array[5]=func_37;
    func_array[6]=func_38;
    func_array[7]=func_39;
    func_array[8]=func_3a;
    func_array[9]=func_3b;
    func_array[10]=func_3c;
    func_array[11]=func_3d;
    func_array[12]=func_3e;
    func_array[13]=func_3f;
    func_array[14]=func_40;
    func_array[15]=func_41;
    func_array[16]=func_42;
    func_array[17]=func_43;
    func_array[18]=func_44;
    func_array[19]=func_45;
    func_array[20]=func_46;
    func_array[21]=func_47;
    func_array[22]=func_48;
    func_array[23]=func_49;
    func_array[24]=func_4a;
    func_array[25]=func_4b;
    func_array[26]=func_4c;
    func_array[27]=func_4d;
    func_array[28]=func_4e;
    func_array[29]=func_4f;
    func_array[30]=func_50;
    func_array[31]=func_51;
    func_array[32]=func_52;
    func_array[33]=func_53;
    func_array[34]=func_54;
    func_array[35]=func_55;
    func_array[36]=func_56;
    func_array[37]=func_57;
    func_array[38]=func_58;
    func_array[39]=func_59;
    func_array[40]=func_5a;
    func_array[41]=func_5b;
    func_array[42]=func_5c;
    func_array[43]=func_5d;
    func_array[44]=func_5e;
    func_array[45]=func_5f;
    func_array[46]=func_60;
    func_array[47]=func_61;
    func_array[48]=func_62;
    func_array[49]=func_63;
    func_array[50]=func_64;
    func_array[51]=func_65;
    func_array[52]=func_66;
    func_array[53]=func_67;
    func_array[54]=func_68;
    func_array[55]=func_69;
    func_array[56]=func_6a;
    func_array[57]=func_6b;
    func_array[58]=func_6c;
    func_array[59]=func_6d;
    func_array[60]=func_6e;
    func_array[61]=func_6f;
    func_array[62]=func_70;
    func_array[63]=func_71;
    func_array[64]=func_72;
    func_array[65]=func_73;
    func_array[66]=func_74;
    func_array[67]=func_75;
    func_array[68]=func_76;
    func_array[69]=func_77;
    func_array[70]=func_78;
    func_array[71]=func_79;
    func_array[72]=func_7a;
    func_array[73]=func_7b;
    func_array[74]=func_7c;
    func_array[75]=func_7d;
    func_array[76]=func_7e;
    func_array[77]=func_7f;
    func_array[78]=func_80;
    func_array[79]=func_81;
    func_array[80]=func_82;
    func_array[81]=func_83;
    func_array[82]=func_84;
    func_array[83]=func_85;
    func_array[84]=func_86;
    func_array[85]=func_87;
    func_array[86]=func_88;
    func_array[87]=func_89;
    func_array[88]=func_8a;
    func_array[89]=func_8b;
    func_array[90]=func_8c;
    func_array[91]=func_8d;
    func_array[92]=func_8e;
    func_array[93]=func_8f;
    func_array[94]=func_90;
    func_array[95]=func_91;
    func_array[96]=func_92;
    func_array[97]=func_93;
    func_array[98]=func_94;
    func_array[99]=func_95;
    func_array[100]=func_96;
    func_array[101]=func_97;
    func_array[102]=func_98;
    func_array[103]=func_99;
    func_array[104]=func_9a;
    func_array[105]=func_9b;
    func_array[106]=func_9c;
    func_array[107]=func_9d;
    func_array[108]=func_9e;
    func_array[109]=func_9f;
    func_array[110]=func_a0;
    func_array[111]=func_a1;
    func_array[112]=func_a2;
    func_array[113]=func_a3;
    func_array[114]=func_a4;
    func_array[115]=func_a5;
    func_array[116]=func_a6;
    func_array[117]=func_a7;
    func_array[118]=func_a8;
    func_array[119]=func_a9;
    func_array[120]=func_aa;
    func_array[121]=func_ab;
    func_array[122]=func_ac;
    func_array[123]=func_ad;
    func_array[124]=func_ae;
    func_array[125]=func_af;
    func_array[126]=func_b0;
    func_array[127]=func_b1;
    func_array[128]=func_b2;
    func_array[129]=func_b3;
    func_array[130]=func_b4;
    func_array[131]=func_b5;
    func_array[132]=func_b6;
    func_array[133]=func_b7;
    func_array[134]=func_b8;
    func_array[135]=func_b9;
    func_array[136]=func_ba;
    func_array[137]=func_bb;
    func_array[138]=func_bc;
    func_array[139]=func_bd;
    func_array[140]=func_be;
    func_array[141]=func_bf;
    func_array[142]=func_c0;
    func_array[143]=func_c1;
    func_array[144]=func_c2;
    func_array[145]=func_c3;
    func_array[146]=func_c4;
    func_array[147]=func_c5;
    func_array[148]=func_c6;
    func_array[149]=func_c7;
    func_array[150]=func_c8;
    func_array[151]=func_c9;
    func_array[152]=func_ca;
    func_array[153]=func_cb;
    func_array[154]=func_cc;
    func_array[155]=func_cd;
    func_array[156]=func_ce;
    func_array[157]=func_cf;
    func_array[158]=func_d0;
    func_array[159]=func_d1;
    func_array[160]=func_d2;
    func_array[161]=func_d3;
    func_array[162]=func_d4;
    func_array[163]=func_d5;
    func_array[164]=func_d6;
    func_array[165]=func_d7;
    func_array[166]=func_d8;
    func_array[167]=func_d9;
    func_array[168]=func_da;
    func_array[169]=func_db;
    func_array[170]=func_dc;
    func_array[171]=func_dd;
    func_array[172]=func_de;
    func_array[173]=func_df;
    func_array[174]=func_e0;
    func_array[175]=func_e1;
    func_array[176]=func_e2;
    func_array[177]=func_e3;
    func_array[178]=func_e4;
    func_array[179]=func_e5;
    func_array[180]=func_e6;
    func_array[181]=func_e7;
    func_array[182]=func_e8;
    func_array[183]=func_e9;
    func_array[184]=func_ea;
    func_array[185]=func_eb;
    func_array[186]=func_ec;
    func_array[187]=func_ed;
    func_array[188]=func_ee;
    func_array[189]=func_ef;
    func_array[190]=func_f0;
    func_array[191]=func_f1;
    func_array[192]=func_f2;
    func_array[193]=func_f3;
    func_array[194]=func_f4;
    func_array[195]=func_f5;
    func_array[196]=func_f6;
    func_array[197]=func_f7;
    func_array[198]=func_f8;
    func_array[199]=func_f9;
    func_array[200]=func_fa;
    func_array[201]=func_fb;
    func_array[202]=func_fc;
    func_array[203]=func_fd;
    func_array[204]=func_fe;
    func_array[205]=func_ff;
    func_array[206]=func_00;
    func_array[207]=func_01;
    func_array[208]=func_02;
    func_array[209]=func_03;
    func_array[210]=func_04;
    func_array[211]=func_05;
    func_array[212]=func_06;
    func_array[213]=func_07;
    func_array[214]=func_08;
    func_array[215]=func_09;
    func_array[216]=func_0a;
    func_array[217]=func_0b;
    func_array[218]=func_0c;
    func_array[219]=func_0d;
    func_array[220]=func_0e;
    func_array[221]=func_0f;
    func_array[222]=func_10;
    func_array[223]=func_11;
    func_array[224]=func_12;
    func_array[225]=func_13;
    func_array[226]=func_14;
    func_array[227]=func_15;
    func_array[228]=func_16;
    func_array[229]=func_17;
    func_array[230]=func_18;
    func_array[231]=func_19;
    func_array[232]=func_1a;
    func_array[233]=func_1b;
    func_array[234]=func_1c;
    func_array[235]=func_1d;
    func_array[236]=func_1e;
    func_array[237]=func_1f;
    func_array[238]=func_20;
    func_array[239]=func_21;
    func_array[240]=func_22;
    func_array[241]=func_23;
    func_array[242]=func_24;
    func_array[243]=func_25;
    func_array[244]=func_26;
    func_array[245]=func_27;
    func_array[246]=func_28;
    func_array[247]=func_29;
    func_array[248]=func_2a;
    func_array[249]=func_2b;
    func_array[250]=func_2c;
    func_array[251]=func_2d;
    func_array[252]=func_2e;
    func_array[253]=func_2f;
    func_array[254]=func_30;
    func_array[255]=func_31;

    fd = fopen("password.txt", "rb");
    if (NULL == fd)
    {
        printf("[Rhinoxorus] Error: failed to open password.txt!\n");
        exit(1);
    }

    memset(password, 0, sizeof(password));
    fgets(password, sizeof(password), fd);
    fclose(fd);

    newline = strchr(password, 0x0a);
    if (NULL != newline)
    {
        *newline = 0x0;
    }

    tcp_server_loop(24242);
    return 0;
}

