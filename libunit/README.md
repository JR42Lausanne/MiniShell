# Libunit

Unit testing framework writen in C for C.

# Mandatatory part

Your Micro-framework must meet the specifics below:
- [ ] Your source files must be placed in a folder framework
- [ ] The framework must be able to execute a serie of tests one after the other without
interruption.
- [ ] Each test should be stored in a list/array/tree/whatever... with a specific name
which should be written on the standart output.
- [ ] Each test is executed in a separate process. This process will be closed at the end
of the test and it will give the hand back to the parent process.
man fork
- [ ] The parent process must be able to catch the result of the child process or the type
of interruption if it crashes (at least SegFault and BusError)
man exit; man wait; man signal;
6
Rush - libunit What the fork ??
- [ ] At the end of the tests execution, your program should write the name of the tested
functions and the name of each test with the corresponding result on the standard
output according to the following syntax:
	- OK : Test succeeded.
	- KO : Test failed.
	- SEGV : Segmentation Fault detected.
	- BUSE : Bus Error detected.
- [ ] At the end, the total number of tests and the count of succeeded tests must be
displayed.
- [ ] In case of complete success, the routine exits returning 0. If at least one of the
tests failed the routine returns -1.
- [ ] Only the result of each test should be written on the standard output. See the part
below for more informations.
- [ ] You are free to choose the output format as long as everything remains consistent

# TODO list 
