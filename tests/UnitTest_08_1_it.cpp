// UnitTest_08_1_it.cpp
// Рева Максим
// Модульний тест для Lab_08_1_it.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_08_1_it_main
#include "../Lab_08_1_it.cpp"
#undef main

TEST_SUITE("UnitTest_08_1_it")
{
    TEST_CASE("FindThirdComma: find index of third comma")
    {
        CHECK(FindThirdComma("a,b,c,d") == 5);
        CHECK(FindThirdComma(",,,") == 2);
        CHECK(FindThirdComma("12,34,56,78,90") == 8);
        CHECK(FindThirdComma("no commas") == -1);
        CHECK(FindThirdComma("one,two") == -1);
        CHECK(FindThirdComma("one,two,three") == -1); // only 2 commas
        CHECK(FindThirdComma("") == -1);
    }

    TEST_CASE("Change: replace commas with double asterisks")
    {
        char str1[100] = "a,b,c";
        char* res1 = Change(str1);
        CHECK(strcmp(res1, "a**b**c") == 0);
        CHECK(strcmp(str1, "a**b**c") == 0);
        delete[] res1;

        char str2[100] = ",,,";
        char* res2 = Change(str2);
        CHECK(strcmp(res2, "******") == 0);
        CHECK(strcmp(str2, "******") == 0);
        delete[] res2;

        char str3[100] = "hello world";
        char* res3 = Change(str3);
        CHECK(strcmp(res3, "hello world") == 0);
        CHECK(strcmp(str3, "hello world") == 0);
        delete[] res3;

        char str4[100] = "";
        char* res4 = Change(str4);
        CHECK(strcmp(res4, "") == 0);
        CHECK(strcmp(str4, "") == 0);
        delete[] res4;
    }
}
