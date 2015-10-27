/* 
 * File:   temporary_file.cpp
 * Author: thanhpv
 * http://stackoverflow.com/questions/9595511/using-the-filename-generated-from-mkstemp
 * Created on October 27, 2015, 10:29 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int fd;
	char file_path[] = "../bin/temporaryXXXXXX";
	//The file is opened with the open(2) O_EXCL flag, 
	//guaranteeing that the caller is the process that creates the file.
	//The O_EXCL flag prevents you from opening the file again.
	fd = mkstemp(file_path);
	if (fd == -1) {
		printf("Error mktemp %s\n", strerror(errno));
		return -1;
	}
	printf("Generated file name was %s\n", file_path);
	char buf[] = "555";
	int offset = 5;
	pwrite(fd, &buf, strlen(buf), offset);

	char read_buf[200];
	pread(fd, &read_buf, strlen(buf), offset);
	printf("Write buf: %s; Read buf: %s of file %s\n", buf, read_buf, file_path);

	//Name disappears immediately, but the file is removed only after close or process exits
	//Without unlink, after close or process exit, the file will not be deleted
	unlink(file_path);
	pread(fd, &read_buf, strlen(buf), offset);
	printf("After unlink: Write buf: %s; Read buf: %s of file %s\n", buf, read_buf, file_path);
	//
	if (close(fd) == -1) {
		printf("Error close temporary file %s\n", file_path);
		return -1;
	}
	return 0;
}

