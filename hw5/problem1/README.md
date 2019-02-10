# HW5 — Problem 1

## Introduction

One of the nice things about input/output in C++ is that reading from or writing something to file is very similar to reading from or writing to console:

```C++
#include <fstream>

int main()
{
    std::ofstream out( "hello.txt" );
    out << "Hello, world!" << std::endl; // save greeting to "hello.txt" file 
}
```

In fact, the standard output stream (`std::cout`) and an output file stream like `out` in the above example are both derived from the same interface, `std::ostream`. Similarly, the standard input stream (`std::cin`) and an input file stream are both derived from `std::istream`, so you can write a single function that will write to console or file depending on what stream you pass in:

```C++
void hello( std::ostream& out )
{
    out << "Hello, world!" << std::endl;
}

int main()
{
    std::ofstream out( "hello.txt" );
    hello( out ); // save greeting to file
    hello( std::cout ); // print greeting to console
}
```

You can also create an input or output stream that reads or writes to a string:

```C++
int main()
{
    std::stringstream out;
    hello( out ); // print greeting to a string-based stream
    std::cout << out.str(); // print the string to console
}
```

See [this Stack Overlfow answer](https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do/20595061#20595061) for further explanation of  `stringstream` utility.


## Problem statement

You are on a team with Bob and while you were out sick, he thought it'd be fun to volunteer your team to implement simple text-based streaming for the `Shape` class hierarchy from [`lab6`](https://github.com/uiowa-cs-3210-0001/cs3210-labs/tree/master/lab6/1%20-%20class%20hierarchies). As usual, when it came to actually doing the work, Bob quickly gave up and left it to you to finish the assignment. 

Copy the code from [`lab6`](https://github.com/uiowa-cs-3210-0001/cs3210-labs/tree/master/lab6/1%20-%20class%20hierarchies) into this repo and modify/complete it to make Bob's  `main.cpp` (provided in this repo) compile, run, and write on disk two text files that match the files provided in the `expected` folder. Do not modify Bob's `main.cpp`. 

Use C++ abstraction mechanisms to avoid/eliminate copy & paste (including existing copy & paste in `lab6` source code).
