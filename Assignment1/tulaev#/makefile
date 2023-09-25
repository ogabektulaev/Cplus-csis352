#macros	
CC = g++
OBJECTS = main.o token.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog1

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp queueType.h stackType.h token.h
		$(CC) $(CFLAGS) -c main.cpp	

token.o: 	token.cpp token.h
		$(CC) $(CFLAGS) -c token.cpp	

clean:
		rm -rf prog1 *~ $(OBJECTS) $(EXE)
