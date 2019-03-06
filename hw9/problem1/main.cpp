#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "phonebook.hpp"

TEST_CASE("PhoneBook", "[PhoneBook]")
{
    using namespace cs3210;
    PhoneBook phonebook;
    REQUIRE( phonebook.empty() );

    phonebook.add( { "Alice", phone_number( "502-854-6705" ) } );
    phonebook.add( { "Bob", phone_number( "209-271-1438" ) } );
    phonebook.add( { "Adam", phone_number( "870-862-2261" ) } );
    phonebook.add( { "Abigail", phone_number( "253-886-7578" ) } );
    phonebook.add( { "Zoe", phone_number( "918-781-7517" ) } );
    REQUIRE( !phonebook.empty() );
    REQUIRE( phonebook.size() == 5 );

    auto const alice_records = phonebook.lookup( "Alice" );
    REQUIRE( alice_records.size() == 1 );
    REQUIRE( alice_records.front().phone_number == "502-854-6705" );

    REQUIRE( phonebook.lookup( "Alex" ).empty() );

    phonebook.add( { "Bob", phone_number( "386-427-8635" ) } );
    auto const bob_records = phonebook.lookup( "Bob" );
    REQUIRE( !bob_records.empty() );
    REQUIRE( bob_records.size() == 2 );
    REQUIRE( bob_records.front().name == "Bob" );
    REQUIRE( bob_records.front().phone_number == "209-271-1438" );
    REQUIRE( bob_records.back().name == "Bob" );
    REQUIRE( bob_records.back().phone_number == "386-427-8635" );

    REQUIRE( phonebook.lookup( phone_number( "918-781-7517" ) ) == "Zoe" );
    REQUIRE( phonebook.lookup( phone_number( "209-271-1438" ) ) == "Bob" );
    REQUIRE( phonebook.lookup( phone_number( "555-555-5555" ) ) == "" );

    std::vector<PhoneBook::value_type> entries;
    for ( auto& entry : phonebook )
        entries.push_back( entry );

    REQUIRE( entries.size() == 6 );

    auto const alphabetic = phonebook.alphabetic_order();
    REQUIRE( alphabetic.size() == 6 );

    auto iter = alphabetic.begin();
    REQUIRE( ( iter++ )->name == "Abigail" );
    REQUIRE( ( iter++ )->name == "Adam" );
    REQUIRE( ( iter++ )->name == "Alice" );
    REQUIRE( ( iter++ )->name == "Bob" );
    REQUIRE( ( iter++ )->name == "Bob" );
    REQUIRE( ( iter++ )->name == "Zoe" );

    phonebook.add( { "Bob Dylan", phone_number( "209-271-1438" ) } );
    REQUIRE( phonebook.size() == 6 );
    REQUIRE( phonebook.lookup( phone_number( "209-271-1438" ) ) == "Bob Dylan" );

    phonebook.remove( phone_number( "386-427-8635" ) );
    REQUIRE( phonebook.size() == 5 );
    REQUIRE( phonebook.lookup( phone_number( "386-427-8635" ) ) == "" );

    phonebook.clear();
    REQUIRE( phonebook.empty() );
    REQUIRE( phonebook.size() == 0 );
}
