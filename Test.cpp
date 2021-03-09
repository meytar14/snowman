/*
AUTHORS:Meytar
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    //check the hat
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces("___ \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces(" _\n/_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces(" ___\n (_*_)\n(.,.)\n( : )\n( : )"));
    //check the nose
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
    //check the left eye 
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
    //check the right eye 
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
     //check the left arm
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
     //check the right arm
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    //check the torso
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(   )\n( : )"));
    //check the base
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(" ")"));
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));
   }

TEST_CASE("Bad snowman code") {
    //check the length of the string
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12343));
    CHECK_THROWS(snowman(123433));
    CHECK_THROWS(snowman(1234332));
    CHECK_THROWS(snowman(123433212));
    //throw exception if one of the numbers is not between 1-4
    CHECK_THROWS(snowman(52341321));
    CHECK_THROWS(snowman(10342321));
    CHECK_THROWS(snowman(12542321));
    CHECK_THROWS(snowman(12202321));
    CHECK_THROWS(snowman(12245321));
    CHECK_THROWS(snowman(12243021));
    CHECK_THROWS(snowman(12243291));
    CHECK_THROWS(snowman(12243248));
}

