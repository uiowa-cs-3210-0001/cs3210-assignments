#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "string.hpp"
#include <stdexcept>
#include <cstring>


TEST_CASE( "String basics", "[string]" ) 
{
    using cs3210::string;
    
    string const s;
    REQUIRE( s.empty() );

    char const* str = "Hello";
    string const hello( str );
    REQUIRE( hello.length() == 5 );
    REQUIRE( !hello.empty() );
    REQUIRE( hello.c_str() != str );
    REQUIRE( std::strcmp( hello.c_str(), str ) == 0 );

    string const hello_world( hello + ", world" );
    REQUIRE( hello_world == "Hello, world" );
    REQUIRE( "Hello, world" == hello_world );

    string hello_bob( hello );
    hello_bob += ", Bob";
    REQUIRE( hello_bob == "Hello, Bob" );
    REQUIRE( hello_bob[0] == 'H' );
    REQUIRE( hello_bob[1] == 'e' );
    REQUIRE( hello_bob[2] == 'l' );
    REQUIRE_THROWS_AS( hello_bob[20], std::range_error );

    REQUIRE( hello_bob.substr() == hello_bob );
    REQUIRE( hello_bob.substr( 0, 5 ) == hello );
    REQUIRE( hello_bob.substr( 7, 100 ) == "Bob" );

    string s1;
    s1 = hello_bob;
    REQUIRE( s1 == hello_bob );

    REQUIRE( string( nullptr ).empty() );

    REQUIRE( string( "abcd" ) < string( "bcde" ) );
    REQUIRE( "abcd" < string( "bcde" ) );
    REQUIRE( string( "abcd" ) <= string( "bcde" ) );
    REQUIRE( string( "abcd" ) <= "abcd" );

    REQUIRE( string( "abcde" ) > string( "abcd" ) );
    REQUIRE( "abcde" > string( "abcd" ) );
    REQUIRE( string( "abcde" ) >= string( "abcd" ) );
    REQUIRE( string( "abcd" ) >= "abcd" );
}
