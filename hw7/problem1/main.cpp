#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "point.hpp"
#include <sstream>


TEST_CASE( "Point<int>", "[Point]" ) 
{
    Point<int> p1;
    REQUIRE(p1.x == 0);
    REQUIRE(p1.y == 0);
    REQUIRE(p1 == p1);

    Point p2(1, -1);
    REQUIRE(p2.x == 1);
    REQUIRE(p2.y == -1);
    REQUIRE(p2 != p1);
    REQUIRE(p2 != Point(1, 0));
    REQUIRE(p2 != Point(0, -1));

    REQUIRE(p1 + p2 == p2);
    REQUIRE(p2 - p1 == p2);
    REQUIRE(-p2 == Point(-1, 1));

    REQUIRE(p1 * p2 == p1);
    REQUIRE(p1 / p2 == p1);

    REQUIRE(p2 * 10 == Point(10, -10));
    REQUIRE(10 * p2 == Point(10, -10));
    REQUIRE(p2 / 1 == p2);

    REQUIRE( ( p2 += Point(10, 10) ) == Point(11, 9) );
    REQUIRE( ( p2 -= Point(10, 10) ) == Point(1, -1) );
    REQUIRE( ( p2 *= Point(10, 10) ) == Point(10, -10) );
    REQUIRE( ( p2 /= Point(-1, -1) ) == Point(-10, 10) );

    REQUIRE( &( p2 += Point(10, 10) ) == &p2 );
    REQUIRE( &( p2 -= Point(10, 10) ) == &p2 );
    REQUIRE( &( p2 *= Point(10, 10) ) == &p2 );
    REQUIRE( &( p2 /= Point(-1, -1) ) == &p2 );

    REQUIRE( Point<int>(-1, -1) < Point(0, 0) );
    REQUIRE( Point<int>(-1, -1) <= Point(-1, 0) );
    REQUIRE( Point<int>(-1, -1) <= Point(-1, -1) );
    REQUIRE( !( Point<int>(-1, -1) < Point(-1, -1) ) );
    REQUIRE( !( Point<int>(0, -1) < Point(-1, -1) ) );
    REQUIRE( !( Point<int>(0, 0) < Point(-1, -1) ) );
    REQUIRE( Point<int>(-1, -1) >= Point(-1, -1) );
    REQUIRE( Point<int>(-1, 0) >= Point(-1, -1) );
    REQUIRE( Point<int>(0, 0) > Point(-1, -1) );

    std::stringstream ss;
    ss << Point(100, -100);
    REQUIRE( ss.str() == "(100,-100)" );
}


TEST_CASE( "Point<double>", "[Point]" ) 
{
    Point<double> p1;
    REQUIRE(p1.x == 0.0);
    REQUIRE(p1.y == 0.0);
    REQUIRE(p1 == p1);

    Point p2(1.1, -1.5);
    REQUIRE(p2.x == 1.1);
    REQUIRE(p2.y == -1.5);
    REQUIRE(p2 != p1);

    REQUIRE(p1 + p2 == p2);
    REQUIRE(p2 - p1 == p2);
    REQUIRE(-p2 == Point(-1.1, 1.5));

    REQUIRE(p1 * p2 == p1);
    REQUIRE(p1 / p2 == p1);

    REQUIRE(p2 * 10.0 == Point(11.0, -15.0));
    REQUIRE(10.0 * p2 == Point(11.0, -15.0));
    REQUIRE(p2 / 1.0 == p2);

    std::stringstream ss;
    ss << Point(100.102, -100.502);
    REQUIRE( ss.str() == "(100.102,-100.502)" );
}
