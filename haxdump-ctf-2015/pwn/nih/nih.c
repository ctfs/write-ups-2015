#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct{
  unsigned int octets[4];
} Address;

typedef struct{
  Address addr;
  Address mask;
} Subnet;

void error(char* s){
  puts(s);
  exit(-1);
}

char* addr_string(Address* a){
  char* rv = NULL;
  asprintf(&rv, "%d.%d.%d.%d",a->octets[0],a->octets[1],a->octets[2],a->octets[3]);
  return rv;
}
  
int filter(Address* a){
  if(a->octets[0] == 127) error("Sorry, 127.0.0.0/8 is a blocked subnet.");
  if(a->octets[0] == 54) error("Sorry, 54.0.0.0/8 is a blocked subnet.");
  if(a->octets[0] == 0) error("Sorry, 0.0.0.0/8 is blocked subnet.");
  return 1;
}

int main(int argc, char *argv[]){
  int sockfd, i;
  Address a;

  setbuf(stdout, NULL);

  puts("NIH Proxy");
  puts("Specify an HTTP server to connect to");
  puts("DNS is too hard; just provide an IP address");

  char target[20];
  fgets(target, 20, stdin);
  char* octet = strtok(target, ".\n");
  
  for(i=0;i<4;i++){
    if(!octet) error("Invalid IP address");
    a.octets[i] = atoi(octet);
    if(a.octets < 0 || a.octets[i] > 256) {
      fprintf(stderr, "Invalid host\n");
      exit(-1);
    }
    octet = strtok(NULL, ".\n");
  }

  filter(&a);
  printf("Connecting to %s\n", addr_string(&a));

  int sin_addr = 0;
  
  for(i=0; i<4;i++){
    sin_addr <<= 8;
    sin_addr |= a.octets[i];
  }
  
  struct sockaddr_in serv_addr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);
  serv_addr.sin_addr.s_addr = htonl(sin_addr);

  alarm(5);
  connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
  char *buf = calloc(256, 1);

  int len = sprintf(buf, "GET / HTTP/1.1\nHost: %s\n\n", addr_string(&a));
  write(sockfd, buf, len);
  int total_len = 0;
  while(total_len < 1024*10){
    len = read(sockfd, buf, 255);
    if(len <= 0) break;
    total_len += len;
    buf[len] = 0;
    fputs(buf, stdout);
    if(len < 255) break;
  }
  close(sockfd);
  return 0;
}
