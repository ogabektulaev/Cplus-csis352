//Ogabek Tulaev, jj0565yv
//CSIS 352-01


Assignment 3
==========================================================
This program implements and tests an array that 
throws exceptions when different potential errors occur. 
For example, an out-of-bounds exception, an array length 
exception, exceptions to check for negative indices, or 
other types of potential errors could be avoided.


*User should enter an integer number as the size of the array.


tulaev#.zip 
==========================================================
main.cpp
myArray.h
extraExceptions.h
README.txt
makefile



How to Run:
==========================================================
1. Type "make" into the terminal while in /tulaev#/ to 
compile program.
2. Type "prog3" to run the program.
3. Enter "make clean" to remove files created from compiling.

Example output:
==========================================================
"""""
jj0565yv@smaug:~/Downloads/Assignment_3$ make
g++ -fno-diagnostics-color -Wall -c main.cpp
g++ -fno-diagnostics-color -Wall -o prog3 main.o 
jj0565yv@smaug:~/Downloads/Assignment_3$ prog3

Creating first array of type int
Array initialized. Size: 5
Array contents: 0 0 0 0 0 
Changing array numbers...
Array contents: 10 100 1000 50 1
10 100 1000 50 1 
Last item in the array is 1

Creating second array of type double
Array initialized. Size: 5
Array contents: 0 0 0 0 0 
Changing array numbers...
Array contents: 9.2 1.1 300.23 17.3 6.5
9.2 1.1 300.23 17.3 6.5 
Last item in the array is 6.5

Creating third array, a copy of array 2
Array contents: 9.2 1.1 300.23 17.3 6.5 

Testing out of range exception with array3[100] = 100;
 Error - Index must be less than the length of the array

Testing out invalid array length with myArray<double>(-5);
 Error - array length must be greater than zero

Testing out custom exception for big sized array (size<=1000);
 Error - the size of the array is too big, it should be less than 1000!

jj0565yv@smaug:~/Downloads/Assignment_3$

""""


Bug testing
==========================================================
Please, let me know if you find any bugs.

jj0565yv@go.minnstate.edu


Others
==========================================================
The program is made in collababoration with  Asadbek.
He worked with exceptions.

