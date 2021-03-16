
#include "snowman.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * an array of colors 
 */
const string colors[] =
{"\x1B[0m","\x1B[31m","\x1B[32m", "\x1B[33m","\x1B[34m", "\x1B[35m", "\x1B[36m", "\x1B[37m"};

  int main() {
    
    int flag_correct_input=1;
    int input=0;
    while(flag_correct_input) {  //as long as we did not get the right input 
        cout << "Please enter 8 digits to determine the shape of the snowman: "<<endl;
        try{
            cin >> input; // get user input from the keyboard to "input"
            //displays the snowman by input in random colors 
            cout << colors[rand() % 7] << "Here's the snowman you built:\n" << ariel::snowman(input)<<endl;
            flag_correct_input=0; //we got a right input now we will stop the loop 
        }
        catch(exception& e){
            cout << "Incorrect input, please try again\n" << endl; 
        }
    }
}

/**
 Examples that can be examined: 
 12222212 ---> should print:
 _===_
\(o.o)/
 ( : ) 
 (" ")

 32443333 ---> should print:
   _
  /_\
 (-.-) 
/(> <)\
 (___)

11114411 ---> should print:
_===_
(.,.)
( : )
( : )

 */

