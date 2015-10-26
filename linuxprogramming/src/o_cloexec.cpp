/* 
 * File:   o_cloexec.cpp
 * Author: thanhpv
 * Describe o_cloexec flag
 * https://lwn.net/Articles/236486/
 * Created on October 26, 2015, 11:20 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	printf("1_PID: %d\n", getpid());
	int fd;
	if (argc > 1) {
		printf("2_PID: %d, Number of argc: %d\n", getpid(), argc);
		for (int i = 0; i < argc; i++) {
			printf("argv[%d] is: %s\n", i, argv[i]);
		}
		fd = atol(argv[1]);
		printf("child: fd = %d\n", fd);
		//fcntl(fd, F_GETFD): get file descriptor flags
		//0 means O_RDONLY
		//1 means O_WRONLY
		if (fcntl(fd, F_GETFD) == 0 || errno != EBADF) {
			puts("file descriptor valid in child");
			return 1;
		}
		return 0;
	}
	printf("3_PID: %d\n", getpid());
	fd = open("/proc/self/exe", O_RDONLY | O_CLOEXEC);
	printf("in parent: new fd = %d\n", fd);
	char buf[20];
	snprintf(buf, sizeof (buf), "%d", fd);
	execl("/proc/self/exe", argv[0], buf, NULL);
	puts("execl failed");
	return 1;
}

