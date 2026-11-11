// UnitTest_08_2.cpp
// Рева Максим
// Модульний тест для Lab_08_2.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_08_2_main
#include "../Lab_08_2.cpp"
#undef main

TEST_SUITE("UnitTest_08_2")
{
    TEST_CASE("IsDelimiter: checks space and punctuation characters")
    {
        CHECK(IsDelimiter(' ') == true);
        CHECK(IsDelimiter('\t') == true);
        CHECK(IsDelimiter(',') == true);
        CHECK(IsDelimiter('.') == true);
        CHECK(IsDelimiter('!') == true);
        CHECK(IsDelimiter('?') == true);
        CHECK(IsDelimiter(';') == true);
        CHECK(IsDelimiter(':') == true);
        CHECK(IsDelimiter('-') == true);

        CHECK(IsDelimiter('a') == false);
        CHECK(IsDelimiter('Z') == false);
        CHECK(IsDelimiter('1') == false);
        CHECK(IsDelimiter('_') == true);
    }

    TEST_CASE("MaxWordLength: calculates length of the longest word")
    {
        CHECK(MaxWordLength("Hello, world! Programming is fun.") == 11);
        CHECK(MaxWordLength("one two three") == 5);
        CHECK(MaxWordLength("a bb ccc dddd") == 4);
        CHECK(MaxWordLength("SingleWord") == 10);
        CHECK(MaxWordLength("   ... ,,, !!!   ") == 0);
        CHECK(MaxWordLength("") == 0);
        CHECK(MaxWordLength("Word1, Word22; Word333! Word4444") == 8);
    }

    TEST_CASE("LongestWord: finds the longest word string")
    {
        CHECK(LongestWord("Hello, world! Programming is fun.") == "Programming");
        CHECK(LongestWord("one two three") == "three");
        CHECK(LongestWord("   ... ,,, !!!   ") == "");
        CHECK(LongestWord("") == "");
        CHECK(LongestWord("word") == "word");
    }
}
