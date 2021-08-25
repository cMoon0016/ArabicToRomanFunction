//
// Created by moon on 25.08.2021.
//

#ifndef ARABICTOROMANNUMBERS_WITH_TESTS_ARABICTOROMAN_H
#define ARABICTOROMANNUMBERS_WITH_TESTS_ARABICTOROMAN_H

#include "string"
#include "exception"

///defining new exception
struct ZeroDontExistInRomanException : public std::exception {
    const char* what() const throw () {
        return "";
    }
};

struct NegativeNumbersDontExistInRomanExcpetion : public std::exception {
    const char* what() const throw () {
        return "";
    }
};



void ThrowExceptionIfNumberIsZero(int arabic) {
    if ( arabic == 0 )
        throw ZeroDontExistInRomanException();
}

void ThrowExceptionIfNumberIsNegative(int arabic) {
    if ( arabic < 0 )
        throw NegativeNumbersDontExistInRomanExcpetion();
}

std::string TranslateValidArabicNumberToRoman(int arabic) {
    const auto ArabicToRomanTable = {
            std::make_pair(1000, "M"),
            std::make_pair(900, "CM"),
            std::make_pair(500, "D"),
            std::make_pair(400, "CD"),
            std::make_pair(100, "C"),
            std::make_pair(90, "XC"),
            std::make_pair(50, "L"),
            std::make_pair(40, "XL"),
            std::make_pair(10, "X"),
            std::make_pair(9, "IX"),
            std::make_pair(5, "V"),
            std::make_pair(4, "IV"),
            std::make_pair(1, "I")
    };

    std::string RomanNumber;

    for ( auto v: ArabicToRomanTable ) {
        while ( arabic >= v.first) {
            RomanNumber += v.second;
            arabic -= v.first;
        }
    }

    return RomanNumber;
}

std::string ArabicToRoman(int arabic) {
    ThrowExceptionIfNumberIsZero(arabic);
    ThrowExceptionIfNumberIsNegative(arabic);
    return TranslateValidArabicNumberToRoman(arabic);
}

#endif //ARABICTOROMANNUMBERS_WITH_TESTS_ARABICTOROMAN_H
