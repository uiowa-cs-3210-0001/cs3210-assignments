# HW6 — Problem 1

## Introduction

One of the most impressive feats of the C++ standard library is that it alows **objects of non-copyable types** (i.e. types with deleted/inaccessible copy constructor and assignment operator) **to be safely stored in the standard library containers** — that is, as long as those non-copyable objects can be moved. Many RAII types — including standard types like [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr) — are non-copyable but moveable, and being able to store them in standard containers allows for a natural expression of a lot of common use cases that otherwise wouldn't be possible to express nearly as simply or elegantly:

```C++
std::vector<std::unique_ptr<Shape>> shapes; // yay!
shapes.push_back( make_unique<Circle>( Point{5,5}, 10 ) );
shapes.push_back( make_unique<Rectangle>( Point{1,1}, Point{10,10} ) );
```

See [Lecture 8 Slides](https://slides.com/agurtovoy/programming-with-cpp-spring-2019-lecture-8#/) for a list of additional resources on RAII, move semantics, etc.


## Problem statement

Bob and Alice decided to adopt the `file_handle` class from [Lab 8](https://github.com/uiowa-cs-3210-0001/cs3210-labs/blob/master/lab8/1%20-%20raii%20(solution).cpp) to fortify some legacy code. Bob wrote a simple test program emulating the production code they were aiming to replace, but it didn't work as he expected. Unable to figure out what's going on, he turned to you.

The program compiles, but does not produce the expected output (see two files in the `expected` folder). Diagnose the issue
and fix the code to make the program correctly save the two files.  Do not modify `main.cpp`.
