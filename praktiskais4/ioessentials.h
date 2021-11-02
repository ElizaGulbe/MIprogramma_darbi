/**
 * Fails, kurs nodrosina ar stream I/O funckijam
 * Ka ari paligfunkcijam, kuras lauj apstradat 'string' ka 'int'
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include <cstdlib>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


// checks if string s is equal to a whole number
bool isWholeNumber(const std::string& s) {
    if(s == "") return false;

    if(s[0] == '-' || (s[0] >= '0' && s[0] <= '9')) {           // checks for a negative and positive number
        for(int i = 1; i<s.length(); i++) {                     // checks each char for a digit
            if(s[i]<'0' || s[i]>'9') {
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;
}
// changes string to int if 's' can be legally casted to int
int changeStringToInt(const std::string& s) {
    int sInt;
    if(!isWholeNumber(s)) throw std::invalid_argument("String is not a whole number");
    std::stringstream ss(s);
    ss >> sInt;
    return sInt;
}

// namespace containing essential IO stream functions
namespace ioessent {
    // clears console
    void clearCout() {
        std::cout << std::flush;
        system(CLEAR);
    }

    // function, which goes in a loop, printing 'message' and taking int as input each itteration
    // ALWAYS returns an int in range [minRange, maxRange]
    // except when range is impossible, then throws exception
    int getNumberInRangeWithoutFail(const std::string& message, const int& minRange, const int& maxRange) {
        if(minRange>maxRange) throw std::invalid_argument("Number out of range.");      // checks if range real
        int numb;
        std::string numbStr;
        do {
            std::cout << message;
            std::getline(std::cin, numbStr);
            try {                                                                       // converts string to number
                numb = changeStringToInt(numbStr);
            }
            catch(const std::invalid_argument& e) {
                continue;                                                               // if fail, repeat the loop
            }
        } while (!isWholeNumber(numbStr) || numb > maxRange || numb < minRange);        // check range and check if 'numbStr' is whole number to not let 'continue' statement break out of loop
        return numb;
    }

    // function, which prints 'message' and takes an int as input once
    // if int entered in correct format and in range defined by [minRange, maxRange], then return this int
    // else throw exception
    int getNumberInRangeWithFail(const std::string& message, const int& minRange, const int& maxRange) {
        if(minRange>maxRange) throw std::invalid_argument("Number out of range.");      // checks if range real
        int numb;
        std::string numbStr;
        std::cout << message;
        std::getline(std::cin, numbStr);

        try {
            numb = changeStringToInt(numbStr);                                          // converts string to number
        }
        catch(const std::invalid_argument& e) {
            throw std::invalid_argument("Non-number entered.");                         // if fail, pass exception to function call
        }

        if(numb > maxRange || numb < minRange) {
            throw std::invalid_argument("Number out of range.");
        }
        return numb;
    }
    double getDobuleInRangeWithoutFail(const std::string& message, const double& minRange, const double& maxRange) {
        if(minRange>maxRange) throw std::invalid_argument("Number out of range.");      // checks if range real
        double numb;
        std::string numbStr;
        do {
       
            std::cout << message;
            std::getline(std::cin, numbStr);
          
             
            try {                                                                       // converts string to number
               numb = std::stod(numbStr);
                return numb;
    
            }
            catch(const std::invalid_argument& e) {
                continue;                                                               // if fail, repeat the loop
            }
        } while (!isWholeNumber(numbStr) || numb > maxRange || numb < minRange);        // check range and check if 'numbStr' is whole number to not let 'continue' statement break out of loop
        return numb;
    }
}
