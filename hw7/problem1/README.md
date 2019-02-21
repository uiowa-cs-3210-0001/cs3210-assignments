# HW7 — Problem 1

## Introduction

A neat feature of C++ (since C++17) is the ability to omit class template arguments when constructing an object of the specific class template instance **if the compiler can deduce the said template arguments from the type of the object's initializer**, similarly to how it deduces function template arguments from the function arguments. For example:

```C++
std::pair<int,double> p1( 17, 42.0 ); // OK, nothing special here...
std::pair p2( 17, 42.0 ); // Also okay! std::pair's template arguments (<int,double>) 
                          // are deduced from the initializer expression 

auto p3 = std::pair( 17, 42.0 ) // Also okay, same as above
std::vector v = { 3.14159, 2.71828, 1.41421 }; // deduced as std::vector<double>
```

As the class template author, in most cases you don't have to do anything special to enable this feature — the compiler simply does it for you. Sometimes, though, the compiler does not have enough information to do what we want, and for these cases the language provides a mechanism to explicitly steer the class template argument deduction (CTAD) with [user-defined deduction guides](https://devblogs.microsoft.com/cppblog/how-to-use-class-template-argument-deduction/).

Note that the latest version of Clang has [a bug](https://bugs.llvm.org/show_bug.cgi?id=34091) that sometimes prevents the compiler from properly applying CTAD on temporary objects — thus the redundant template arguments in this assignment's code.


## Problem statement

Armed with the advanced knowledge of class and function templates from this week's training, Alice decided to take her basic geometry library from [hw3/problem2](https://github.com/uiowa-cs-3210-0001/cs3210-assignments/tree/master/hw3/problem2) and make it more generic. She turned her `Point` class into a class template, added some functionality, and substantially extended her test suite. Just as she was finishing up, Bob came up and asked if she had an interesting small problem he can use to sharpen his "generic programming skills." "Well, you can finish this," said Alice, checking in the test case without the header files. 

An hour later Bob came to you, asking for help.

Using the code you submitted for [hw3/problem2](https://github.com/uiowa-cs-3210-0001/cs3210-assignments/tree/master/hw3/problem2) as a starting point, create a new header file `point.hpp`, turn your `Point` class into a class template, and implement its expected interface using tests in `main.cpp` as guidance. Make sure to check out [hw3 postmortem](https://gist.github.com/agurtovoy/8a1ee8fa36fe1240b77e90ea3f2b9216) to avoid making the same mistakes as before. Do not modify  `main.cpp` .
