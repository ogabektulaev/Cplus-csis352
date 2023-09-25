#macros	
CC = g++
OBJECTS = main.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog3

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp myArray.h extraExceptions.h
		$(CC) $(CFLAGS) -c main.cpp

clean:
		rm -rf prog3 *~ $(OBJECTS) $(EXE)
