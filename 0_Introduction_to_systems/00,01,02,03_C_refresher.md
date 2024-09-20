# ch:1 BASICS of C

## 1.1 C- compiling and running programs

- Python is interpreted => another program(the Python interpreter) runs Python programs: the Python inter­preter acts like a virtual machine on which Python programs are run.
- the program source code (hello.py) is given as input
  to the Python interpreter program that runs it.
- the Python interpreter is a binary executable that can be run directly on the underlying system(OS and hardware).
- gcc -o hello hello.c
- using Makefile is important
- On a 32/64-bit system, int is typically 32 bits(4bytes) in size, with a range of -2147483648(= -2^32) to 2147483647(= 2^32-1).
- You can print the exact size on a given machine using C’s sizeof operator.
- int-float arithmetic operation => results float

## 1.2 1.2 Input/Output (printf and scanf)

- The printf and scanf functions belong to C’s standard I/O library(#include <stdio.h>)
- %g specifier is particularly useful when you want to print floating-point numbers in a way that optimizes for readability by choosing the shortest representation
- Prefixing the name of a variable with the & operator produces the location of that variable in the program’s memory — the memory address of the variable.

## 1.3 conditionals and loops

- logical and (&&): stops evaluating at the first false expression (short­ circuiting);
- logical or (||): stops evaluating at the first true expression (short­ circuiting).
- In C, for loops and while loops are equivalent in power, meaning that any while loop can be expressed as a for loop, and vice versa. The same is not true in Python, where for loops are iterations over a sequence of values.
- for: use for definite loops(like iterating over a range of
  values), while: use for indefinite loops(like repeating until the user enters an even number).

## 1.4 functions

- Functions that don’t return a value should specify the **void** return type.
- Arguments to C functions are passed by value: each function parame­ter is assigned the value of the corresponding argument passed to it in the function call by the caller
- **Pass by value** semantics mean that any change to a parameter’s value in the function (that is, assigning a parameter a new valuein the function) is not visible to the caller.
- The **execution stack** keeps track of the state of active functions in a program. Each function call creates a new stack frame (sometimes called an **activation frame** or **activation record**) containing its parameter and local variable val­ues.
- **Prototypes** is a declaration of a function that specifies its name, return type, and the types and number of its parameters. It serves as a contract between the function definition and its callers, allowing the compiler to perform type checking and ensure that function calls are made with the correct arguments.
- The scope of a function prototype extends from its declaration to the end of the file. It can be declared at any point before it is used in the code. However, it is common practice to place all prototypes at the beginning of the program or in header files.

## 1.5 Statically declared => Arrays and Strings

- Accessing array beyond declaration(out of bound) can lead to unexpected program behavior, thus, as a C programmer, it’s up to you to ensure that your array accesses refer to valid positions!
- The capac­ity of the array parameter(in FUNCTION) arr isn’t specified: arr[] means that this function can be called with an array argument of any capacity.
- In C, the name of the array variable is equivalent to the base address of the array (i.e., the **memory address of its 0th element**). Due to C’s pass by value function call semantics, when you pass an array to a function, each ele­ment of the array is not individually passed to the function.
- the function isn’t receiving a copy of each array element. Instead, an array parameter gets the copy of the array’s base address. This behavior implies that when a function modifies the elements of an array that was passed as a pa­rameter, the changes will persist when the function returns. (SEE ./changing_arr.c)
- It is difficult to track string size, so strings in C must end with a special character value, **the null character ('\0')**, to indicate the end of the string.
- When we scanf string , we dont use address(&) => char name[20]; scanf("%[^\n]",name); because name is base address as explained above.

## 1.6 Structs

- Collection of data elements of different types.

- When we assign one struct var with another, it copies values not references.

- C provides a sizeof operator that takes a type and returns the number of bytes used by the type.

- single variables of base types, array-elements, and structs are all **lvalues** i.e, they can appear on the left side of an assignment statement.

- passing a struct as an argument to a function gives the parameter a copy of all the argument struct’s field values.

- If the function changes the field values of a struct parameter, the changes to the parameter’s field val­ues have no effect on the corresponding field values of the argument. That is, changes to the **parameter’s fields** only modify values in the parameter’s memory locations for those fields, not in the **argument’s memory locations** for those fields.
