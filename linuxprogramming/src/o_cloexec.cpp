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
int main_o_cloexec(int argc, char** argv) {
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
	//With O_CLOEXEC => 
	//Output:
	//1_PID: 7994
	//3_PID: 7994
	//in parent: new fd = 3
	//1_PID: 7994
	//2_PID: 7994, Number of argc: 2
	//argv[0] is: ./GetOpenFileFlag
	//argv[1] is: 3
	//child: fd = 3
	fd = open("/proc/self/exe", O_RDONLY | O_CLOEXEC);

	//With O_CLOEXEC=>
	//1_PID: 8381
	//3_PID: 8381
	//in parent: new fd = 3
	//1_PID: 8381
	//2_PID: 8381, Number of argc: 2
	//argv[0] is: ./GetOpenFileFlag
	//argv[1] is: 3
	//child: fd = 3
	//file descriptor valid in child	// fd 3 is not closed and visible in child process
//	fd = open("/proc/self/exe", O_RDONLY);
	printf("in parent: new fd = %d\n", fd);
	char buf[20];
	snprintf(buf, sizeof (buf), "%d", fd);
	execl("/proc/self/exe", argv[0], buf, NULL);
	puts("execl failed");
	return 1;
}

