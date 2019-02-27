# HW8 — Problem 1

## Introduction

C++ string literals are simply char arrays terminated by a null character:

```C++
char const* str1 = "Hi there";
char const str2[] = { 'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', '\0' }; // same as above
char const str3[] = { 'H', 'i', ' ', 't', 'h', 'e', 'r', 'e', 0 }; // ditto
```

This format of string representation is called [_null-terminated_ strings](https://en.wikipedia.org/wiki/Null-terminated_string) or _C-style strings_. The length of a null-terminated string is found by searching for the (first) null character. This can be slow, as it takes linear time (_O(n)_) with respect to the string length. It also means that a null character cannot be a part of the string, as it's the very first null that marks the end:

```C++
char const* str = "Hi\0 there";
std::cout << str; // Oops, prints "Hi" instead of "Hi\0 there"
```

While C++ provides us with a standard library type, `std::string`, that shields us from most of the pains of working with low-level C-style strings directly, it's instructive to consider how `std::string` class might be implemented.

## Problem statement

After reading [std::string vs C-strings](https://embeddedartistry.com/blog/2017/7/24/stdstring-vs-c-strings) blog post referenced in [h4 postmortem](https://gist.github.com/agurtovoy/90e0d925e4b9ea06d25ddcb0f02e8eab), Bob has decided to implement a simple equivalent of `std::string` to better understand the mechanics of classes, memory management, constructors/destructors, and copy/assignment operators. Having also recently read about test-driven development, he asked if Alice could write a test suite he could use to develop against. Alice was happy to help and produced a set of tests in `main.cpp`. Thinking it's actually a neat exercise, she then shared her code with you.

Use the tests in `main.cpp` as guidance and the standard C++ library functions for working with C-style strings ([`std::strlen`](), [`std::strncpy`](), [`std::strcmp`](), etc.), implement a user-defined `string` type that provides an interface similar to `std::string` and guarantees _O(1)_ complexity for its `string::length` method. Declare the `string` class in the `string.hpp`, implement all non-trivial string methods in the `string.cpp`.  Do not modify  `main.cpp` .
