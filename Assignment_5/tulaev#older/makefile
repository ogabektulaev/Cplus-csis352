#macros	
CC = g++
OBJECTS = main.o tree.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog5

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp tree.h 
		$(CC) $(CFLAGS) -c main.cpp	

tree.o: tree.cpp tree.h
		$(CC) $(CFLAGS) -c tree.cpp

clean:
		rm -rf prog5 *~ $(OBJECTS) $(EXE)
