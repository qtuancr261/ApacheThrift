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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/myclientapplication.o \
	${OBJECTDIR}/myserviceclientrunnable.o \
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
LDLIBSOPTIONS=-L/usr/local/lib `pkg-config --libs thrift` `pkg-config --libs poco_foundation` `pkg-config --libs poco_util`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pococlientapp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pococlientapp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pococlientapp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/MyService.o: MyService.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyService.o MyService.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/myclientapplication.o: myclientapplication.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/myclientapplication.o myclientapplication.cpp

${OBJECTDIR}/myserviceclientrunnable.o: myserviceclientrunnable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/myserviceclientrunnable.o myserviceclientrunnable.cpp

${OBJECTDIR}/thrift_file_constants.o: thrift_file_constants.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift_file_constants.o thrift_file_constants.cpp

${OBJECTDIR}/thrift_file_types.o: thrift_file_types.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g `pkg-config --cflags thrift` `pkg-config --cflags poco_foundation` `pkg-config --cflags poco_util`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift_file_types.o thrift_file_types.cpp

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
