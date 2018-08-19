
BIN=bin/
SRC=src/
LIB=lib/
OBJ=obj/

OS := $(shell uname)
ifeq ($(OS),Darwin)
LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT
else
LDFLAGS = -lGL -lGLU -lglut
endif

all:	${BIN}lonely-arm

${BIN}lonely-arm:   ${OBJ}camera.o ${OBJ}arm.o ${OBJ}plataforma.o ${OBJ}parts.o ${OBJ}trabalho.o 
	@/bin/echo -e "\n\e[1;34mCompiling obeject files:\e[0m"
	g++ -o ${BIN}lonely-arm ${OBJ}plataforma.o ${OBJ}camera.o ${OBJ}trabalho.o ${OBJ}arm.o ${OBJ}parts.o  $(LDFLAGS)

${OBJ}camera.o: ${SRC}camera.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}camera.o ${SRC}camera.cpp

${OBJ}game.o:	${SRC}game.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}trabalho.o ${SRC}game.cpp

${OBJ}arm.o:	${SRC}arm.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}arm.o ${SRC}arm.cpp

${OBJ}platform.o:	${SRC}platform.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}plataforma.o ${SRC}platform.cpp

${OBJ}parts.o:	${SRC}parts.cpp
	g++ -O0 -g3 -Wall -I${LIB} -c -fmessage-length=0 -o ${OBJ}parts.o ${SRC}parts.cpp





edit:	
	vim -p Makefile src/* lib/*

clean:	
	@/bin/echo -e "\n\e[1;34mCleaning project...\e[0m"
	@rm -rf ${OBJ}*.o
	@rm -f ${BIN}lonely-arm

run:	all
	./${BIN}lonely-arm
