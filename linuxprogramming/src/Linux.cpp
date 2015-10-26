/* 
 * File:   Linux.cpp
 * Author: thanhpv
 *
 * Created on October 9, 2015, 11:54 PM
 */

#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include "error_functions.h"

#define MAX_READ 1024

using namespace std;

/*
 * 
 */
int main_(int argc, char** argv) {


	/**
	 * Read STDIN
	 * @param argc
	 * @param argv
	 * @return 
	 */
	//	char buffer[MAX_READ];
	//	int numRead = read(STDIN_FILENO, buffer, MAX_READ);
	//	if (numRead == -1)
	//		errExit("read standard input");
	//	buffer[numRead] = '\0';
	//	printf("The input is: %s\n", buffer);

	/**
	 * GET_PID
	 * @param argc
	 * @param argv
	 * @return 
	 */
	//	printf("%ld\n", (long)getpid());

	/**
	 * OPEN FILE EXCLUSIVE
	 * @param argc
	 * @param argv
	 * @return 
	 */
	//	printf("%ld\n", (long) getpid());
	//	int fd;
	//	if (open(argv[1], O_WRONLY) == -1) {
	//		if (errno != ENOENT) { //no such file or directory
	//			printf("%s\n", strerror(errno));
	//			errExit("open");
	//		} else {
	//			sleep(5);
	//			//always use that if open file and create file if not exist.
	//			fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
	//			if (fd == -1){
	//				printf("%s\n", strerror(errno));
	//				errExit("open");
	//			}
	//			printf("[PID %ld] created file \"%s\" exclusively\n", (long) getpid(), argv[1]);
	//		}
	//	} else {
	//		printf("[PID %ld] File \"%s\" already exists\n", (long) getpid(), argv[1]);
	//	}

	/**
	 * Use O_APPEND to make sure always write to ends
	 * @param argc
	 * @param argv
	 * @return 
	 */
	//	int fd;
	//	char buffer[10];
	//	strcpy(buffer, "bbbb");
	//	//with O_APPEND, content will be always written to end of file
	//	fd = open(argv[1], O_WRONLY | O_APPEND);
	//	//overwrite old content
	//	//	fd = open(argv[1], O_WRONLY);
	//	if (fd == -1) {
	//		printf("%s\n", strerror(errno));
	//		errExit("open");
	//	} else {
	//		//sleep 5 then write
	//		//will overwrite the content written by previous process
	//		//		sleep(5);
	//		lseek(fd, 0, SEEK_SET);
	//		write(fd, buffer, 5);
	//	}

	/**
	 * Get open file access mode + flags by fcntl.
	 * @param argc
	 * @param argv
	 * @return 
	 */
	//	printf(" Read only: %d; Write only: %d; Read and Write: %d; Access mode: %d\n", O_RDONLY, O_WRONLY, O_RDWR, O_ACCMODE);
	//	printf(" Append: %d; Async: %d; Sync: %d\n", O_APPEND, O_ASYNC, O_SYNC);

	//	int fd = open(argv[1], O_SYNC | O_WRONLY);
	//	if (fd == -1) {
	//		errExit("open %s", argv[1]);
	//	}
	//	int flags = fcntl(fd, F_GETFL);
	//	if (flags & O_SYNC) {
	//		printf("File %s is for synchronized\n", argv[1]);
	//	}
	//	if (flags & O_RDONLY) {
	//		printf("File %s is for read only\n", argv[1]);
	//	}
	//	if (flags & O_WRONLY) {
	//		printf("File %s is for write only\n", argv[1]);
	//	}
	//	
	//	printf("O_ACCMODE: %d O_WRONLY: %d O_WRONLY: %d O_RDWR: %d\n", O_ACCMODE, O_RDONLY, O_WRONLY, O_RDWR);
	//	if (O_SYNC & O_SYNC) {
	//		printf("O_SYNC & O_SYNC True\n");
	//	}
	//	if (O_RDONLY & O_RDONLY) {
	//		printf("O_RDONLY & O_RDONLY True\n");
	//	}
	//	if (O_WRONLY & O_WRONLY) {
	//		printf("O_WRONLY & O_WRONLY True\n");
	//	}
	//	if (O_RDWR & O_RDWR) {
	//		printf("O_RDWR & O_RDWR True\n");
	//	}
	//	if (O_RDWR & O_RDONLY) {
	//		printf("O_RDWR & O_RDONLY True\n");
	//	}
	//	if (O_RDWR & O_WRONLY) {
	//		printf("O_RDWR & O_WRONLY True\n");
	//	}

	/**
	 * Duplicate File Descripttors
	 * @param argc
	 * @param argv
	 * @return 
	 */

	char file_path[200];
	strcpy(file_path, "../bin/dup_fd_test.txt");
	int fd1 = open(file_path, O_RDWR);
	if (fd1 < 0) {
		printf("Error open file %s\n", strerror(errno));
		return -1;
	}
	//dup
	//	int fd2 = dup(fd1);

	//dup2
	//return fd of duplicate fd on success.
	//close(3) if any already opened with that fd
	//	int fd2 = dup2(fd1, 4);

	//fcntl
	//makes a duplicate of old fd by using the lowest fd greater than or equal to startfd
	//return code on error is differ from dup2 and dup
	//	int fd2 = fcntl(fd1, F_DUPFD, fd1);

	//dup3
	//makes a duplicate of old fd, same as dup2 but support O_CLOEXEC flag
	//fd1 and fd2 share the same file offset and status flag	
	
	int fd2 = dup3(fd1, 4, O_CLOEXEC);
	if (fd2 < 0) {
		printf("Error duplicate fd %s\n", strerror(errno));
		return -1;
	}
	char buff[200];
	strcpy(buff, "cccc");
	write(fd1, &buff, strlen(buff));
	strcpy(buff, "dddd");
	write(fd2, &buff, strlen(buff));
	printf("First fd is: %d; second fd is: %d\n", fd1, fd2);
	close(fd1);
	close(fd2);
	return 0;
}

