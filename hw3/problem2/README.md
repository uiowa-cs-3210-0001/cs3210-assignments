# HW3 — Problem 2

## Introduction

Another characteristic C++ feature is _operator overloading_: the ability for C++ operators to have user-defined meanings on user-defined types:

```C++
class Point { ... };
class Rectangle { ... };

int main()
{
    Rectangle r(0,0,20,10);
    r += Point(5,5); // move by 5 pixels on both axis
}
```

For more details, see [this operator overloading guide](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr318.htm) from IBM, the excellent [Operator Overloading FAQ](https://isocpp.org/wiki/faq/operator-overloading) at [isocpp.org](https://isocpp.org), and [operator overloading reference](https://en.cppreference.com/w/cpp/language/operators) at [cppreference.com](https://en.cppreference.com).

## Problem statement

Alice started working on beginnings of a basic geometry library along the lines of the above example, but got pulled into another project before she could finish it. She passed on her `point.cpp` file to you, asking you to flesh out the `Point` class definition to make the tests pass.

## Stretch goal (optional)

Implement and test other operators that you think would make sense for this class.
