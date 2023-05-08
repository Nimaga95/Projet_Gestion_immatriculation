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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/4d6aed64/ContratException.o \
	${OBJECTDIR}/_ext/4d6aed64/ValidationFormat.o \
	${OBJECTDIR}/_ext/4d6aed64/Vehicule.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp2.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp2.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp2.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp2.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtp2.a

${OBJECTDIR}/_ext/4d6aed64/ContratException.o: ../../Informatique/Projets\ Gits/Labo5/TP2_C++/ContratException.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4d6aed64
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d6aed64/ContratException.o ../../Informatique/Projets\ Gits/Labo5/TP2_C++/ContratException.cpp

${OBJECTDIR}/_ext/4d6aed64/ValidationFormat.o: ../../Informatique/Projets\ Gits/Labo5/TP2_C++/ValidationFormat.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4d6aed64
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d6aed64/ValidationFormat.o ../../Informatique/Projets\ Gits/Labo5/TP2_C++/ValidationFormat.cpp

${OBJECTDIR}/_ext/4d6aed64/Vehicule.o: ../../Informatique/Projets\ Gits/Labo5/TP2_C++/Vehicule.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/4d6aed64
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/4d6aed64/Vehicule.o ../../Informatique/Projets\ Gits/Labo5/TP2_C++/Vehicule.cpp

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
