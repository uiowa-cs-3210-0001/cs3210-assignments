#include "census.hpp"
#include "person.hpp"
#include <iostream>
using namespace std;

int main()
{
    hw4::Person bob{ "Bob", 42 };
    hw4::Person alice{ "Alice", 21 };
    cout
        << bob << endl // Bob, 42
        << alice << endl; // Alice, 21

    hw4::Census census( 2019 );
    census.add( bob );
    census.add( alice );
    cout << "count: " << census.count() << endl; // count: 2
}
