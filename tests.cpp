//
// Created by moon on 25.08.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ArabicToRoman.h"

TEST(ArabicToRoman, ReturnStringNULLIfArabicIsZero) {
    ASSERT_THROW(ArabicToRoman(0), ZeroDontExistInRomanException);
}

TEST(ArabicToRoman, ReturnExceptionIfArgumentIsNegativeNumber) {
    ASSERT_THROW(ArabicToRoman(-5), NegativeNumbersDontExistInRomanExcpetion);
}

TEST(ArabicToRoman, TranslateNumbers) {
    EXPECT_THAT(ArabicToRoman(4), testing::Eq("IV"));
    ASSERT_THAT(ArabicToRoman(11), "XI");
    ASSERT_THAT(ArabicToRoman(40), "XL");
    ASSERT_THAT(ArabicToRoman(154), "CLIV");
    ASSERT_THAT(ArabicToRoman(1000), "M");
}