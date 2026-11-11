// UnitTest_08_1_rec.cpp
// Рева Максим
// Модульний тест для Lab_08_1_rec.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_08_1_rec_main
#include "../Lab_08_1_rec.cpp"
#undef main

TEST_SUITE("UnitTest_08_1_rec")
{
    TEST_CASE("FindThirdComma: recursive search for index of third comma")
    {
        CHECK(FindThirdComma("a,b,c,d", 0, 0) == 5);
        CHECK(FindThirdComma(",,,", 0, 0) == 2);
        CHECK(FindThirdComma("12,34,56,78,90", 0, 0) == 8);
        CHECK(FindThirdComma("no commas", 0, 0) == -1);
        CHECK(FindThirdComma("one,two", 0, 0) == -1);
        CHECK(FindThirdComma("one,two,three", 0, 0) == -1);
        CHECK(FindThirdComma("", 0, 0) == -1);
    }

    TEST_CASE("Change: recursive replacement of commas with double asterisks")
    {
        char dest1[100] = "";
        Change(dest1, "a,b,c", dest1, 0);
        CHECK(strcmp(dest1, "a**b**c") == 0);

        char dest2[100] = "";
        Change(dest2, ",,,", dest2, 0);
        CHECK(strcmp(dest2, "******") == 0);

        char dest3[100] = "";
        Change(dest3, "hello world", dest3, 0);
        CHECK(strcmp(dest3, "hello world") == 0);

        char dest4[100] = "";
        Change(dest4, "", dest4, 0);
        CHECK(strcmp(dest4, "") == 0);
    }
}
