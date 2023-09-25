#macros	
CC = g++
OBJECTS = main.o ternarySearchNonRecursive.o ternarySearchRecursive.o ternarySearchThirdVariation.o
LFLAGS = 
CFLAGS = -fno-diagnostics-color -Wall
EXE = prog6

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
		
main.o: 	main.cpp ternarySearchNonRecursive.h ternarySearchRecursive.h ternarySearchThirdVariation.h
		$(CC) $(CFLAGS) -c main.cpp

ternarySearchNonRecursive.o:  ternarySearchNonRecursive.cpp ternarySearchNonRecursive.h
		$(CC) $(CFLAGS) -c ternarySearchNonRecursive.cpp

ternarySearchRecursive.o:  ternarySearchRecursive.cpp ternarySearchRecursive.h
		$(CC) $(CFLAGS) -c ternarySearchRecursive.cpp

ternarySearchThirdVariation.o:  ternarySearchThirdVariation.cpp ternarySearchThirdVariation.h
		$(CC) $(CFLAGS) -c ternarySearchThirdVariation.cpp

clean:
		rm -rf prog6 *~ $(OBJECTS) $(EXE)
