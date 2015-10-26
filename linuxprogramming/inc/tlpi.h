/* 
 * File:   tlpi.h
 * Author: thanhpv
 *
 * Created on October 9, 2015, 11:55 PM
 */

#ifndef TLPI_H
#define	TLPI_H

#include <sys/types.h> /*many type definitions*/
#include <stdio.h>/*standard i/o functions*/
#include <stdlib.h>/*many commonly used library functions + EXIT_SUCCESS + EXIT_FAILURE*/
#include <unistd.h>/*many system call functions*/
#include <errno.h>/*declare errno + error constants*/
#include <string.h>/*string handling functions*/
#include "get_num.h"
#include "error_functions.h"

typedef enum {
	FALSE, TRUE
} Boolean;

#define min(m,n) ((m<n)?m:n)
#define max(m,n) ((m>n)?m:n)
#endif	/* TLPI_H */

