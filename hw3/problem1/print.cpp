#include "print.hpp"

int main()
{
    int i = 17;
    int* ptr = &i;

    print(true); // prints "true"
    print(5); // prints "5"
    print(5.5); // prints "5.50"
    print("hello"); // prints "hello"
    print(ptr); // prints the ptr value in hex
    print(Person("Bob", 42)); // prints "Bob, 42"
    print(traffic_light::green); // prints "green"
    print(traffic_light::yellow); // prints "yellow"
    print(traffic_light::red); // prints "red"
}