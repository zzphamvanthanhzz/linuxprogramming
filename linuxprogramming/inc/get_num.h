/* 
 * File:   get_num.h
 * Author: thanhpv
 *
 * Created on October 10, 2015, 12:03 AM
 */

#ifndef GET_NUM_H
#define	GET_NUM_H

#define GN_NONNEG 01
#define GN_GT_0 02

#define GN_ANY_BASE
#define GN_BASE_8
#define GN_BASE_16
/**
 * 
 * @param arg: string to change to Int or long
 * @param flags: control over operations of getInt and getLong
 * @param name: if not NULL, contains a string identifying the argument in arg.
 * @return 
 */
int getInt(const char* arg, int flags, const char* name);
long getLong(const char* arg, int flags, const char* name);


#endif	/* GET_NUM_H */

