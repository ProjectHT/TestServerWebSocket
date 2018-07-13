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
	${OBJECTDIR}/Camera/Camera.o \
	${OBJECTDIR}/Camera/InterfaceCamera.o \
	${OBJECTDIR}/WebSocket/base64.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-L/usr/local/lib -Wl,-rpath,'/usr/local/lib' -lpthread -ldl `pkg-config --libs openssl` -lboost_atomic -lboost_chrono -lboost_container -lboost_context -lboost_contract -lboost_coroutine -lboost_date_time -lboost_filesystem -lboost_graph -lboost_iostreams -lboost_locale -lboost_log -lboost_log_setup -lboost_math_c99 -lboost_math_c99f -lboost_math_c99l -lboost_math_tr1 -lboost_math_tr1f -lboost_math_tr1l -lboost_prg_exec_monitor -lboost_program_options -lboost_python27 -lboost_random -lboost_regex -lboost_serialization -lboost_signals -lboost_stacktrace_addr2line -lboost_stacktrace_backtrace -lboost_stacktrace_basic -lboost_stacktrace_noop -lboost_system -lboost_thread -lboost_timer -lboost_type_erasure -lboost_unit_test_framework -lboost_wave -lboost_wserialization `pkg-config --libs libavcodec-ffmpeg` `pkg-config --libs libavformat-ffmpeg` `pkg-config --libs libavutil-ffmpeg` `pkg-config --libs libswresample-ffmpeg` `pkg-config --libs libswscale-ffmpeg` `pkg-config --libs opencv`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/testserverwebsocket

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/testserverwebsocket: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/testserverwebsocket ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Camera/Camera.o: Camera/Camera.cpp
	${MKDIR} -p ${OBJECTDIR}/Camera
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include `pkg-config --cflags openssl` `pkg-config --cflags libavcodec-ffmpeg` `pkg-config --cflags libavformat-ffmpeg` `pkg-config --cflags libavutil-ffmpeg` `pkg-config --cflags libswresample-ffmpeg` `pkg-config --cflags libswscale-ffmpeg` `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camera/Camera.o Camera/Camera.cpp

${OBJECTDIR}/Camera/InterfaceCamera.o: Camera/InterfaceCamera.cpp
	${MKDIR} -p ${OBJECTDIR}/Camera
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include `pkg-config --cflags openssl` `pkg-config --cflags libavcodec-ffmpeg` `pkg-config --cflags libavformat-ffmpeg` `pkg-config --cflags libavutil-ffmpeg` `pkg-config --cflags libswresample-ffmpeg` `pkg-config --cflags libswscale-ffmpeg` `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camera/InterfaceCamera.o Camera/InterfaceCamera.cpp

${OBJECTDIR}/WebSocket/base64.o: WebSocket/base64.cpp
	${MKDIR} -p ${OBJECTDIR}/WebSocket
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include `pkg-config --cflags openssl` `pkg-config --cflags libavcodec-ffmpeg` `pkg-config --cflags libavformat-ffmpeg` `pkg-config --cflags libavutil-ffmpeg` `pkg-config --cflags libswresample-ffmpeg` `pkg-config --cflags libswscale-ffmpeg` `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WebSocket/base64.o WebSocket/base64.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include `pkg-config --cflags openssl` `pkg-config --cflags libavcodec-ffmpeg` `pkg-config --cflags libavformat-ffmpeg` `pkg-config --cflags libavutil-ffmpeg` `pkg-config --cflags libswresample-ffmpeg` `pkg-config --cflags libswscale-ffmpeg` `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
