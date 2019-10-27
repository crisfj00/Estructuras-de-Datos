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
	${OBJECTDIR}/include/vector_dinamico.o \
	${OBJECTDIR}/src/Ingredientes.o \
	${OBJECTDIR}/src/ingrediente.o \
	${OBJECTDIR}/src/prueba\ vector.o \
	${OBJECTDIR}/src/test_ingredientes.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ingrediente

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ingrediente: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ingrediente ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/include/vector_dinamico.o: include/vector_dinamico.cpp
	${MKDIR} -p ${OBJECTDIR}/include
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/vector_dinamico.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/include/vector_dinamico.o include/vector_dinamico.cpp

${OBJECTDIR}/src/Ingredientes.o: src/Ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/vector_dinamico.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Ingredientes.o src/Ingredientes.cpp

${OBJECTDIR}/src/ingrediente.o: src/ingrediente.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/vector_dinamico.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ingrediente.o src/ingrediente.cpp

.NO_PARALLEL:${OBJECTDIR}/src/prueba\ vector.o
${OBJECTDIR}/src/prueba\ vector.o: src/prueba\ vector.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/vector_dinamico.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/prueba\ vector.o src/prueba\ vector.cpp

${OBJECTDIR}/src/test_ingredientes.o: src/test_ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/vector_dinamico.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test_ingredientes.o src/test_ingredientes.cpp

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
