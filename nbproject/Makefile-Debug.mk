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
	${OBJECTDIR}/Inventory.o \
	${OBJECTDIR}/Room.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/RoomObject.o \
	${OBJECTDIR}/Item.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/ActionMenu.o \
	${OBJECTDIR}/DrawAble.o


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
LDLIBSOPTIONS=-L../../Libs/LaurentGomila-SFML-bdfc2dc/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/devgame

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/devgame: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/devgame ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Inventory.o: Inventory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Inventory.o Inventory.cpp

${OBJECTDIR}/Room.o: Room.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Room.o Room.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Player.o: Player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/RoomObject.o: RoomObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/RoomObject.o RoomObject.cpp

${OBJECTDIR}/Item.o: Item.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Item.o Item.cpp

${OBJECTDIR}/Game.o: Game.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/Menu.o: Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/ActionMenu.o: ActionMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ActionMenu.o ActionMenu.cpp

${OBJECTDIR}/DrawAble.o: DrawAble.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../Libs/LaurentGomila-SFML-bdfc2dc/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawAble.o DrawAble.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/devgame

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
