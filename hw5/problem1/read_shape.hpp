#ifndef CS3210_HW5_PROBLEM1_READ_SHAPE_HPP
#define CS3210_HW5_PROBLEM1_READ_SHAPE_HPP

#include "shape.hpp"
#include <memory>
#include <iosfwd>

// You'll have to implement this one, too 
// -Bob
std::unique_ptr<Shape> read_shape( std::istream& );

#endif
