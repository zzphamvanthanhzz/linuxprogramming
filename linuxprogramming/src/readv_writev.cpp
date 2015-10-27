/* 
 * File:   readv_writev.cpp
 * Author: thanhpv
 *
 * Created on October 27, 2015, 9:28 PM
 */

#include <cstdlib>
#include <sys/fcntl.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <errno.h>
#include "error_functions.h"
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main_readv_writev(int argc, char** argv) {
	int fd;
	struct iovec iov[3];
	struct stat myStruct;//first buffer
	int x; //second buffer
#define STR_SIZE 100
	char str[STR_SIZE]; //third buffer
	ssize_t numRead, totRequired;
	
	if(argc !=2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file\n", argv[0]);
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		printf("Error open file %s error %s\n", argv[1], strerror(errno));
		close(fd);
		return -1;
	}
	totRequired = 0;
	iov[0].iov_base = &myStruct;
	iov[0].iov_len = sizeof(struct stat);
	totRequired += iov[0].iov_len;
	
	iov[1].iov_base = &x;
	iov[1].iov_len = sizeof(x);
	totRequired += iov[1].iov_len;
	
	iov[2].iov_base = str;
	iov[2].iov_len = STR_SIZE;
	totRequired += iov[2].iov_len;
	
	numRead = readv(fd, iov, 3);
	if(numRead == -1){
		printf("Error readv %s\n", strerror(errno));
		close(fd);
		return -1;
	}
	if(numRead < totRequired)
		printf("Read fewer than requested\n");
	printf("total bytes requested: %ld; bytes read: %ld \n", (long)totRequired, (long)numRead);
	close(fd);
	return 0;
}

