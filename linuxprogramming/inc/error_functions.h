/* 
 * File:   error_functions.h
 * Author: thanhpv
 *
 * Created on October 10, 2015, 12:03 AM
 */

#ifndef ERROR_FUNCTIONS_H
#define	ERROR_FUNCTIONS_H

void errMsg(const char* format, ...); /*print error message on standard*/
#ifdef __GNUC__
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char* format, ...) NORETURN; /*print error message + terminate program by calling exit() or abort()*/
void err_exit(const char* format, ...) NORETURN; /*same as errExit, but does not flush standard output before printing error message 
												  by calling _exit() instead of exit()*/
void errExitEN(int errnum, const char* format, ...) NORETURN;/*same as errExit but with errnum*/
void fatal(const char* format, ...) NORETURN;/*handle general errors, include errors from library functions
											  that not set errno
											  print the error and then terminate the program*/
void usageErr(const char* format, ...) NORETURN;/*handle errors in command-line argument usage*/
void cmdLineErr(const char* format, ...) NORETURN;
#endif	/* ERROR_FUNCTIONS_H */

