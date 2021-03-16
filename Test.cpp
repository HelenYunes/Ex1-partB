
#include <algorithm>
#include <string>
#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;
using namespace std; 
  
// Function to remove all spaces from a given string 
string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

TEST_CASE("Too few digits"){
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(2222222));
    CHECK_THROWS(snowman(3333333));
    CHECK_THROWS(snowman(4444444));
}

TEST_CASE("Too many digits"){
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(1111111111));
    CHECK_THROWS(snowman(222222222));
    CHECK_THROWS(snowman(333333333));
    CHECK_THROWS(snowman(444444444));
    CHECK_THROWS(snowman(123412341));
}

TEST_CASE("Digits larger than the range"){
    CHECK_THROWS(snowman(12341219));
    CHECK_THROWS(snowman(43232182));
    CHECK_THROWS(snowman(31333742));
    CHECK_THROWS(snowman(24264411));
    CHECK_THROWS(snowman(54114432));
    CHECK_THROWS(snowman(10112311));
}

TEST_CASE("Matching strings") {
    CHECK(removeSpaces(snowman(11111111)) == removeSpaces(string("       \n _===_ \n (.,.) \n<( : )>\n ( : ) ")));
    CHECK(removeSpaces(snowman(22222222)) == removeSpaces(string("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") ")));
    CHECK(removeSpaces(snowman(33333333)) == removeSpaces(string("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) ")));
    CHECK(removeSpaces(snowman(44444444)) == removeSpaces(string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) ")));
    CHECK(removeSpaces(snowman(12341214)) == removeSpaces(string("       \n _===_ \n (O.-)/\n<( : ) \n (   ) ")));
    CHECK(removeSpaces(snowman(43232122)) == removeSpaces(string("  ___  \n (_*_) \n\\(o_O) \n (] [)>\n (\" \") ")));
    CHECK(removeSpaces(snowman(31333342)) == removeSpaces(string("   _   \n  /_\\  \n (O,O) \n/(   )\\\n (\" \") ")));
    CHECK(removeSpaces(snowman(24224411)) == removeSpaces(string("  ___  \n ..... \n (o o) \n ( : ) \n ( : ) ")));
    CHECK(removeSpaces(snowman(44114432)) == removeSpaces(string("  ___  \n (_*_) \n (. .) \n (> <) \n (\" \") ")));
    CHECK(removeSpaces(snowman(11112311)) == removeSpaces(string("       \n _===_ \n\\(.,.) \n ( : )\\\n ( : ) ")));
    CHECK(removeSpaces(snowman(23232223)) == removeSpaces(string("  ___  \n ..... \n\\(o_O)/\n (] [) \n (___) ")));
    CHECK(removeSpaces(snowman(12333321)) == removeSpaces(string("       \n _===_ \n (O.O) \n/(] [)\\\n ( : ) ")));
    CHECK(removeSpaces(snowman(11114411)) == removeSpaces(string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) ")));
    CHECK(removeSpaces(snowman(12222212)) == removeSpaces(string("       \n _===_ \n\\(o.o)/\n ( : ) \n (\" \") ")));
    CHECK(removeSpaces(snowman(33232124)) == removeSpaces(string("   _   \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) ")));
    CHECK(removeSpaces(snowman(32443333)) == removeSpaces(string("   _   \n  /_\\  \n (-.-) \n/(> <)\\\n (___) ")));
    CHECK(removeSpaces(snowman(44444432)) == removeSpaces(string("  ___  \n (_*_) \n (- -) \n (> <) \n (\" \") ")));
    CHECK(removeSpaces(snowman(43443334)) == removeSpaces(string("  ___  \n (_*_) \n (-_-) \n/(> <)\\\n (   ) ")));
    CHECK(removeSpaces(snowman(44242123)) == removeSpaces(string("  ___  \n (_*_) \n\\(o -) \n (] [)>\n (___) ")));
    CHECK(removeSpaces(snowman(41341144)) == removeSpaces(string("  ___  \n (_*_) \n (O,-) \n<(   )>\n (   ) ")));
    
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(-23232223));
    CHECK_THROWS(snowman(-41341144));
    CHECK_THROWS(snowman(-12222212));
    CHECK(removeSpaces(snowman(11111111)) != removeSpaces(string("       \n _===_ \n (o,.) \n<( : )>\n ( : ) ")));
    CHECK(removeSpaces(snowman(22222222)) != removeSpaces(string("  ___  \n ..... \n\\(o_o)/\n (] [)> \n (\" \") ")));
    CHECK(removeSpaces(snowman(33333333)) != removeSpaces(string("   _   \n  /_\\  \n (O_O) \n/(   )\\\n (___) ")));
    CHECK(removeSpaces(snowman(44444444)) != removeSpaces(string("  ___  \n (_*_) \n (- -) \n (   ) \n ( : ) ")));
    
}


