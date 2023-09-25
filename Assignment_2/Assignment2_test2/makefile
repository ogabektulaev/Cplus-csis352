#macros	
CC = g++
OBJECTS = main.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog2

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp heapType.h
		$(CC) $(CFLAGS) -c main.cpp

clean:
		rm -rf prog2 *~ $(OBJECTS) $(EXE)
