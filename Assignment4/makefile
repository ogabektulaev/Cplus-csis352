#macros	
CC = g++
OBJECTS = main.o josephus.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog4

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp josephus.h
		$(CC) $(CFLAGS) -c main.cpp

josephus.o:  josephus.cpp josephus.h
		$(CC) $(CFLAGS) -c josephus.cpp

clean:
		rm -rf prog4 *~ $(OBJECTS) $(EXE)
