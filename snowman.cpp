#include <iostream>
#include "snowman.hpp"
#include <string>
#include <stdexcept>
#include <array>
using namespace std;

const int  NUMBER_OF_OPTIONS = 4;
const int INPUT_LENGTH = 8;

/**
 * all snowman parts by order.
 */
enum snowmanParts { hat, nose, leftEye, rightEye, leftArm, rightArm, torso, base };
/**
 * all the options for each part of snowman 
 */
const std::array< string, NUMBER_OF_OPTIONS> Hat = {    "\n _===_","  ___\n .....","   _\n  /_\\","  ___\n (_*_)"};
const std::array< string, NUMBER_OF_OPTIONS> Nose = {",", ".", "_", " "};
const std::array< string, NUMBER_OF_OPTIONS> Eye = {".", "o", "O", "-"};
const std::array< string, NUMBER_OF_OPTIONS> UpperLeftArm = {" ", "\\", " ", " "};
const std::array< string, NUMBER_OF_OPTIONS> LowerLeftArm = {"<", " ", "/", " "};
const std::array< string, NUMBER_OF_OPTIONS> UpperRightArm = {" ", "/", " ", " "};
const std::array< string, NUMBER_OF_OPTIONS> LowerRightArm = {">", " ", "\\", " "};
const std::array< string, NUMBER_OF_OPTIONS> Torso = {" : ", "] [", "> <", "   "};
const std::array< string, NUMBER_OF_OPTIONS> Base = {" : ", "\" \"" , "___", "   "};


//returns the option number from string
static int toInt(char option){
    return option-'1'; 
}

namespace ariel{

    string snowman(int snowmanShape){
    
        string outputOfsnowman;
        string shape = to_string(snowmanShape);
        //too many or too few digits 
        if(shape.size() != INPUT_LENGTH){
         throw invalid_argument{"Incorrect input: The input should be exactly 8 digits\n"};
    } 
    for (int i = 0; i < shape.size(); i++){
        if(shape[i] < '1' || shape[i] > '4'){
            //digits out of range 
            throw invalid_argument{"Incorrect input: The input should be in the range of 1-4\n"};
        }
    }

       /**
        * constructs the snowman in the following way 
        *                        Hat
        *   UpperLeftArm(leftEyeNoserightEye)UpperRightArm
        *   LowerLeftArm(       Torso       )LowerRightArm
        *               (        Base       )
        * 
        */
        return  Hat.at(toInt(shape[hat]))+'\n'+
                UpperLeftArm.at(toInt(shape[leftArm]))+"("+Eye.at(toInt(shape[leftEye]))+Nose.at(toInt(shape[nose]))+Eye.at(toInt(shape[rightEye]))+')'+UpperRightArm.at(toInt(shape[rightArm]))+'\n'+
                LowerLeftArm.at(toInt(shape[leftArm]))+'('+ Torso.at(toInt(shape[torso]))+')'+LowerRightArm.at(toInt(shape[rightArm]))+'\n'+
                " ("+ Base.at(toInt(shape[base]))+')';
    }

}