/* 
 * File:   pread_pwrite.cpp
 * Author: thanhpv
 *
 * Created on October 27, 2015, 9:04 PM
 */

#include <cstdlib>
#include <string>
#include <sys/fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main_pread_pwrite(int argc, char** argv) {
	std::string file_path = "../bin/pread_pwrite.txt";
	int offset = 5;
	//open file
	int fd = open(file_path.c_str(), O_RDWR);
	if(fd < 0){
		printf("Error open file %s error %s\n", file_path.c_str(), strerror(errno));
		return -1;
	}
	char buf[50];
	strcpy(buf, "345");
	if(pwrite(fd, &buf, strlen(buf), offset) == -1){
		printf("Write error file %s error %s\n", file_path.c_str(), strerror(errno));
		close(fd);
		return -1;
	}
	char read_buf[200];
	if(pread(fd, &read_buf, sizeof(buf), offset) == -1){
		printf("Read error file %s error %s\n", file_path.c_str(), strerror(errno));
		close(fd);
		return -1;
	}
	printf("Write string is: %s\n", read_buf);
	close(fd);
	return 0;
}

//write from offset 5:      345