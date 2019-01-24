# HW3 — Problem 1

## Introduction

One of the characteristic features of C++ is _function overloading_: the ability to define **more than one function with the same name** in the same scope.

If two functions are defined with the same name, but with different argument types, the compiler will choose the most appropriate function to invoke for each call. For example:

```C++
void print(int);     // prints an integer
void print(double);  // prints a floating-point number
void print(string);  // prints a string

int main()
{
    print(42);               // calls print(int)
    print(9.65);             // calls print(double)
    print("Barcelona");      // calls print(string)
}
```

See [here](https://docs.microsoft.com/en-us/cpp/cpp/function-overloading?view=vs-2017) and [here](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr312.htm) for a couple of good in-depth treatments of the topic.

## Problem statement

Alice implemented an extended version of the above example in two files, `print.cpp` and `print.hpp`. Unfortunately, the header file got lost. You are tasked with reconstructing the lost `print.hpp` header based on the code and comments in `print.cpp`. The resulting program should compile, run and print the expected output.
