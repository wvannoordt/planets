LIB_NAME := tracex

ifndef OPTLEVEL
OPTLEVEL := 0
endif

BASEIDIR  := $(shell pwd)
SRC_DIR   := ${BASEIDIR}/src
LIB_DIR   := ${BASEIDIR}/lib
OBJ_DIR   := ${BASEIDIR}/obj
BIN_DIR   := ${BASEIDIR}/bin
UTL_DIR   := ${BASEIDIR}/util
HDR_DIR   := ${BASEIDIR}/include
export BASEIDIR
export LIB_DIR
export HDR_DIR
export BIN_DIR

IFLAGS := -I${HDR_DIR}

SRC_FILES   := $(wildcard ${SRC_DIR}/*.cpp)
SRC_FILES_C := $(wildcard ${SRC_DIR}/*.c)

HEADER_FILES := $(wildcard ${SRC_DIR}/*.h)

OBJ_FILES   := $(patsubst ${SRC_DIR}/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_FILES_C := $(patsubst ${SRC_DIR}/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES_C))

TARGET := ${LIB_DIR}/lib${LIB_NAME}.a

ifndef CC_HOST
CC_HOST := $(shell which g++)
endif

ifndef C_HOST
C_HOST := $(shell which gcc)
endif

HOST_FLAGS   := -O${OPTLEVEL} -Wno-unknown-pragmas -g -fPIC -fpermissive -std=c++11
HOST_FLAGS_C := -O${OPTLEVEL} -g -fPIC -fpermissive

export CC_HOST
export C_HOST
export ICONFIG=-I${HDR_DIR}
export LCONFIG=-L${LIB_DIR} -l${LIB_NAME}

.PHONY: final
final: setup ${OBJ_FILES} ${OBJ_FILES_C}
	${CC_HOST} -fPIC -shared ${COMPILE_TIME_OPT} ${OBJ_FILES} ${OBJ_FILES_C} ${IFLAGS} -o ${TARGET}

${OBJ_FILES}: ${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CC_HOST} ${HOST_FLAGS} ${COMPILE_TIME_OPT} ${IFLAGS} -c $< -o $@

${OBJ_FILES_C}: ${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	${C_HOST} ${HOST_FLAGS_C} ${COMPILE_TIME_OPT} ${IFLAGS} -c $< -o $@

example: final
	${MAKE} -C ./example -f makefile run

setup:
	-rm -r ${HDR_DIR}
	mkdir -p ${LIB_DIR}
	mkdir -p ${OBJ_DIR}
	mkdir -p ${HDR_DIR}
	mkdir -p ${BIN_DIR}
	@for hdr in ${HEADER_FILES} ; do \
		ln -s $${hdr} -t ${HDR_DIR};\
	done

clean:
	-rm -r ${LIB_DIR}
	-rm -r ${OBJ_DIR}
	-rm -r ${HDR_DIR}
	-rm -r ${BIN_DIR}
	${MAKE} -C ./example -f makefile clean
