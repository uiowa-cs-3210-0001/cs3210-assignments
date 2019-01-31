# HW4 — Problem 1

## Introduction

If you want to provide users of your type with the familiar, idiomatic syntax for standard stream input/output, you have to overload the built-in bitshift operators `<<` and `>>` along the following lines:

```C++
class Point { ... };

std::ostream& operator<<(std::ostream& os, Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    Point p(5, 10);
    std::cout << p << std::endl; // prints "(5, 10)"
}
```

See [Overloading the << Operator for Your Own Classes](https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2017) for more details.

On a not-completely-unrelated note, encapsulating your types into a namespace is as easy as this:

```C++
namespace cs3210 {
class Point { ... };
class Rectangle { ... };
}

int main()
{
    cs3210::Point p(5, 10); // Okay

    using namespace cs3210; // you can place a using directive inside of a  function
    Rectangle r(0, 0, 10, 10); // Also okay
}
```

For an in-depth exploration of namespaces, refer to the IBM's [C++ namespaces guide](https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/namespace.htm) or Microsoft's [C++ namespaces](https://docs.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=vs-2017) docs.


## Problem statement

You and your lab partner Bob were tasked with creating an example project demostrating your understanding of namespaces and separate compilation. Bob took the lead, coming up with the example code in `main.cpp`, and the two other translation units, `person.cpp` and `census.cpp`.  He got tired rather quickly after that, though, and passed the unfinished project over to you. Implement the missing `Person` and `Census` classes, then compile and run the project to make sure its output matches your expectations. Do not modify `main.cpp`.
