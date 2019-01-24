#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class Point {};

TEST_CASE( "Point basics", "[Point]" ) 
{
    Point p1;
    REQUIRE(p1.x == 0);
    REQUIRE(p1.y == 0);

    Point p2(1, -1);
    REQUIRE(p2.x == 1);
    REQUIRE(p1.y == -1);

    REQUIRE(p1 + p2 == p2);
    REQUIRE(p2 - p1 == p2);
    REQUIRE(-p2 == Point(-1,1));

    REQUIRE(p2 * 10 == Point(10, -10));
    REQUIRE(p2 / 1 == p2);

    REQUIRE(p1 != p2);

    p2 += Point(1, 1);
    REQUIRE(p2.x == 2);
    REQUIRE(p2.y == 0);
}
