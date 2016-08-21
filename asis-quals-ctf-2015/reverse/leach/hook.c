#include <unistd.h>
#include <time.h>

unsigned int ret = 0;

time_t time(time_t *t) {
	if (t) *t = ret;
	return ret;
}

unsigned int sleep(unsigned int seconds) {
	ret += seconds;
	return 0;
}
