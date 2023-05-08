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
CCC=g++-10
CXX=g++-10
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
	${OBJECTDIR}/Camion.o \
	${OBJECTDIR}/ContratException.o \
	${OBJECTDIR}/Proprietaire.o \
	${OBJECTDIR}/ValidationFormat.o \
	${OBJECTDIR}/Vehicule.o \
	${OBJECTDIR}/VehiculePromenade.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/Camion_Testeur.o \
	${TESTDIR}/tests/Proprietaire_Testeur.o \
	${TESTDIR}/tests/ValidationFormat_Testeur.o \
	${TESTDIR}/tests/VehiculePromenade_Testeur.o \
	${TESTDIR}/tests/Vehicule_Testeur.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsource.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsource.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsource.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsource.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsource.a

${OBJECTDIR}/Camion.o: Camion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camion.o Camion.cpp

${OBJECTDIR}/ContratException.o: ContratException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException.o ContratException.cpp

${OBJECTDIR}/Proprietaire.o: Proprietaire.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Proprietaire.o Proprietaire.cpp

${OBJECTDIR}/ValidationFormat.o: ValidationFormat.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ValidationFormat.o ValidationFormat.cpp

${OBJECTDIR}/Vehicule.o: Vehicule.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vehicule.o Vehicule.cpp

${OBJECTDIR}/VehiculePromenade.o: VehiculePromenade.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VehiculePromenade.o VehiculePromenade.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/Camion_Testeur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/Proprietaire_Testeur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/ValidationFormat_Testeur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/Vehicule_Testeur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread -lgtest_main -lgtest -lpthread 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/VehiculePromenade_Testeur.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lgtest_main -lgtest -lpthread 


${TESTDIR}/tests/Camion_Testeur.o: tests/Camion_Testeur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Camion_Testeur.o tests/Camion_Testeur.cpp


${TESTDIR}/tests/Proprietaire_Testeur.o: tests/Proprietaire_Testeur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Proprietaire_Testeur.o tests/Proprietaire_Testeur.cpp


${TESTDIR}/tests/ValidationFormat_Testeur.o: tests/ValidationFormat_Testeur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ValidationFormat_Testeur.o tests/ValidationFormat_Testeur.cpp


${TESTDIR}/tests/Vehicule_Testeur.o: tests/Vehicule_Testeur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -I/usr/src/gtest/include -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/Vehicule_Testeur.o tests/Vehicule_Testeur.cpp


${TESTDIR}/tests/VehiculePromenade_Testeur.o: tests/VehiculePromenade_Testeur.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/src/gtest/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/VehiculePromenade_Testeur.o tests/VehiculePromenade_Testeur.cpp


${OBJECTDIR}/Camion_nomain.o: ${OBJECTDIR}/Camion.o Camion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Camion.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Camion_nomain.o Camion.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Camion.o ${OBJECTDIR}/Camion_nomain.o;\
	fi

${OBJECTDIR}/ContratException_nomain.o: ${OBJECTDIR}/ContratException.o ContratException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ContratException.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ContratException_nomain.o ContratException.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ContratException.o ${OBJECTDIR}/ContratException_nomain.o;\
	fi

${OBJECTDIR}/Proprietaire_nomain.o: ${OBJECTDIR}/Proprietaire.o Proprietaire.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Proprietaire.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Proprietaire_nomain.o Proprietaire.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Proprietaire.o ${OBJECTDIR}/Proprietaire_nomain.o;\
	fi

${OBJECTDIR}/ValidationFormat_nomain.o: ${OBJECTDIR}/ValidationFormat.o ValidationFormat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ValidationFormat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ValidationFormat_nomain.o ValidationFormat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ValidationFormat.o ${OBJECTDIR}/ValidationFormat_nomain.o;\
	fi

${OBJECTDIR}/Vehicule_nomain.o: ${OBJECTDIR}/Vehicule.o Vehicule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Vehicule.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vehicule_nomain.o Vehicule.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Vehicule.o ${OBJECTDIR}/Vehicule_nomain.o;\
	fi

${OBJECTDIR}/VehiculePromenade_nomain.o: ${OBJECTDIR}/VehiculePromenade.o VehiculePromenade.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VehiculePromenade.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VehiculePromenade_nomain.o VehiculePromenade.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/VehiculePromenade.o ${OBJECTDIR}/VehiculePromenade_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
