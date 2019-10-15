# Intro assignment C++

> Leveres innen 16 okt innen 23:59  Poeng 1

This assignment is created in multiple parts,
each part partly build on each other. Depending
on how good control you feel you have in C++ you
may start directly on parts 2, 3, or 4.

To pass this assignment a complete solution to
part 2, 3, or 4 is required.

The assignment should be programmed in C++ and
the code with accompanying report are to be
submitted. It is expected that the court will
handle a wide range of error conditions.
E.g.that an illegal operator, letter, or no
number is entered.

By operator it is meant + - *and/



## Part 1:

create a program I will read to numbers and an
operator from the keyboard and print out the
results.

### E.g. 

The text behind > in each line is what is
entered in runtime.

Number 1> 20

operator> *

number 2> 5

the answer of 20 * 5 is 100.



## Part 2:

create a program that reads a string containing
two numbers and a operator and print out the
results. The string are to be interpreted by
your programme. 

In the example below both lines should work
equally well:

please enter to numbers with an operator in
between> 10 + 15

the answer to 10 + 15 is 25.

please enter to numbers with an operator in
between> 10+15

the answer to 10 + 15 is 25.



## Part 3:

create a program that reads a string containing
multiple numbers and operators and prints out
the result .

### Example:

please enter the input string> 2 + 3 * 5

2 + 3 * 5 is 17.

 
 
## Part 4:

create a program that reads ace drink containing
multiple numbers and operators and prints out
the result. The addition in part four is that
it should be possible to use  () two control how
the calculation is performed in addition the
program should be able to handle an infinite
number of parameters. You should also try to
add other operators e.g.  % , ^ etc.

a natural extension to this program is also to
create an opportunity to read that string from
the command line as the program is started.

### Example:

Please give the input string> 4 + 5 + (7 + 4) * 3 + 4 * 4 + 9 / 3 + 4 * 12 – 3 / 4

the answer to 4 + 5 + (7 + 4) * 3 + 4 * 4 + 9 / 3 + 4 * 12 – 3 / 4 is 108.25.


## Future updates/bugs:
* Exit key. E.g. press q to exit, or maybe q and then enter.
* Requres ending in a non-bracket symbol. I.e. the input cannot be "2(3+4)", but can be "2(3+4)1".
* Support for special functions like sin() and similar.
* Support for algebra.