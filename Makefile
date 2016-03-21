CC=gcc -std=c11 -g3 -w -o $@
COMPILE=-c $<
VPATH=include
SERVER=server
CLIENT=client

#Build all
all: ${SERVER} ${CLIENT}

#Build server
${SERVER}: server.o TCPSocket.o Configuration.o
	${CC} $^
server.o: server.c
	${CC} -I ${VPATH} ${COMPILE}
TCPSocket.o: implement/TCPSocket.c
	${CC} -I ${VPATH} ${COMPILE}
Configuration.o: implement/Configuration.c
	${CC} -I ${VPATH} ${COMPILE}

#Build client
${CLIENT}: client.o TCPSocket.o Configuration.o
	${CC} $^
client.o: client.c
	${CC} -I ${VPATH} ${COMPILE}

clean:
	rm -rf *.so *.o ${SERVER} ${CLIENT}
