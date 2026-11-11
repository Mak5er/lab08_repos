// UnitTest_08_1_string.cpp
// Рева Максим
// Модульний тест для Lab_08_1_string.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_08_1_string_main
#include "../Lab_08_1_string.cpp"
#undef main

TEST_SUITE("UnitTest_08_1_string")
{
    TEST_CASE("FindThirdComma: string methods search for third comma")
    {
        CHECK(FindThirdComma("a,b,c,d") == 5);
        CHECK(FindThirdComma(",,,") == 2);
        CHECK(FindThirdComma("12,34,56,78,90") == 8);
        CHECK(FindThirdComma("no commas") == string::npos);
        CHECK(FindThirdComma("one,two") == string::npos);
        CHECK(FindThirdComma("one,two,three") == string::npos);
        CHECK(FindThirdComma("") == string::npos);
    }

    TEST_CASE("Change: string replacement of commas with double asterisks")
    {
        string str1 = "a,b,c";
        CHECK(Change(str1) == "a**b**c");
        CHECK(str1 == "a**b**c");

        string str2 = ",,,";
        CHECK(Change(str2) == "******");

        string str3 = "hello world";
        CHECK(Change(str3) == "hello world");

        string str4 = "";
        CHECK(Change(str4) == "");
    }
}
