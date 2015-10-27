#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Linux.o \
	${OBJECTDIR}/src/error_functions.o \
	${OBJECTDIR}/src/get_num.o \
	${OBJECTDIR}/src/o_cloexec.o \
	${OBJECTDIR}/src/o_nonblock.o \
	${OBJECTDIR}/src/pread_pwrite.o \
	${OBJECTDIR}/src/readv_writev.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../../../Netbeans/svn_vng/xallocatorlib/lib/libxallocator.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../bin/GetOpenFileFlag

../bin/GetOpenFileFlag: ../../../../Netbeans/svn_vng/xallocatorlib/lib/libxallocator.a

../bin/GetOpenFileFlag: ${OBJECTFILES}
	${MKDIR} -p ../bin
	${LINK.cc} -o ../bin/GetOpenFileFlag ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Linux.o: src/Linux.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Linux.o src/Linux.cpp

${OBJECTDIR}/src/error_functions.o: src/error_functions.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/error_functions.o src/error_functions.cpp

${OBJECTDIR}/src/get_num.o: src/get_num.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/get_num.o src/get_num.cpp

${OBJECTDIR}/src/o_cloexec.o: src/o_cloexec.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/o_cloexec.o src/o_cloexec.cpp

${OBJECTDIR}/src/o_nonblock.o: src/o_nonblock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/o_nonblock.o src/o_nonblock.cpp

${OBJECTDIR}/src/pread_pwrite.o: src/pread_pwrite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/pread_pwrite.o src/pread_pwrite.cpp

${OBJECTDIR}/src/readv_writev.o: src/readv_writev.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinc -I../../../../Netbeans/svn_vng/xallocatorlib/inc -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/readv_writev.o src/readv_writev.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../bin/GetOpenFileFlag

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
