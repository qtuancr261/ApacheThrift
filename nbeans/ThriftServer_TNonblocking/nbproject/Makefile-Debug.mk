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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/MyService.o \
	${OBJECTDIR}/MyService_server.o \
	${OBJECTDIR}/thrift_file_constants.o \
	${OBJECTDIR}/thrift_file_types.o


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
LDLIBSOPTIONS=-L/usr/local/lib `pkg-config --libs thrift-nb` `pkg-config --libs thrift` `pkg-config --libs libevent` `pkg-config --libs poco_foundation`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftserver_tnonblocking

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftserver_tnonblocking: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftserver_tnonblocking ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/MyService.o: MyService.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/Poco -I/usr/include/boost -I/usr/local/include `pkg-config --cflags thrift-nb` `pkg-config --cflags thrift` `pkg-config --cflags libevent` `pkg-config --cflags poco_foundation` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyService.o MyService.cpp

${OBJECTDIR}/MyService_server.o: MyService_server.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/Poco -I/usr/include/boost -I/usr/local/include `pkg-config --cflags thrift-nb` `pkg-config --cflags thrift` `pkg-config --cflags libevent` `pkg-config --cflags poco_foundation` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyService_server.o MyService_server.cpp

${OBJECTDIR}/thrift_file_constants.o: thrift_file_constants.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/Poco -I/usr/include/boost -I/usr/local/include `pkg-config --cflags thrift-nb` `pkg-config --cflags thrift` `pkg-config --cflags libevent` `pkg-config --cflags poco_foundation` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift_file_constants.o thrift_file_constants.cpp

${OBJECTDIR}/thrift_file_types.o: thrift_file_types.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/Poco -I/usr/include/boost -I/usr/local/include `pkg-config --cflags thrift-nb` `pkg-config --cflags thrift` `pkg-config --cflags libevent` `pkg-config --cflags poco_foundation` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift_file_types.o thrift_file_types.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
