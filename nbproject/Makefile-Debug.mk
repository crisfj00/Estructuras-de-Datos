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
	${OBJECTDIR}/src/acciones.o \
	${OBJECTDIR}/src/cocinero_integral.o \
	${OBJECTDIR}/src/ingrediente.o \
	${OBJECTDIR}/src/ingredientes.o \
	${OBJECTDIR}/src/instrucciones.o \
	${OBJECTDIR}/src/nutricion_receta.o \
	${OBJECTDIR}/src/receta.o \
	${OBJECTDIR}/src/recetas.o \
	${OBJECTDIR}/src/test_ingredientes.o \
	${OBJECTDIR}/src/test_receta.o \
	${OBJECTDIR}/src/tipos_ingredientes.o


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

${OBJECTDIR}/src/acciones.o: src/acciones.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/acciones.o src/acciones.cpp

${OBJECTDIR}/src/cocinero_integral.o: src/cocinero_integral.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/cocinero_integral.o src/cocinero_integral.cpp

${OBJECTDIR}/src/ingrediente.o: src/ingrediente.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ingrediente.o src/ingrediente.cpp

${OBJECTDIR}/src/ingredientes.o: src/ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ingredientes.o src/ingredientes.cpp

${OBJECTDIR}/src/instrucciones.o: src/instrucciones.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/instrucciones.o src/instrucciones.cpp

${OBJECTDIR}/src/nutricion_receta.o: src/nutricion_receta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/nutricion_receta.o src/nutricion_receta.cpp

${OBJECTDIR}/src/receta.o: src/receta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/receta.o src/receta.cpp

${OBJECTDIR}/src/recetas.o: src/recetas.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/recetas.o src/recetas.cpp

${OBJECTDIR}/src/test_ingredientes.o: src/test_ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test_ingredientes.o src/test_ingredientes.cpp

${OBJECTDIR}/src/test_receta.o: src/test_receta.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test_receta.o src/test_receta.cpp

${OBJECTDIR}/src/tipos_ingredientes.o: src/tipos_ingredientes.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -include include/ingrediente.h -include include/ingredientes.h -include include/receta.h -include include/recetas.h -include include/arbolbinario.h -include include/color.h -include include/acciones.h -include include/instrucciones.h -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tipos_ingredientes.o src/tipos_ingredientes.cpp

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
