// Lab_08_2.cpp
// Рева Максим
// Лабораторна робота № 8.2
// Опрацювання літерних рядків
// Варіант 23

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Перевірка, чи є символ розділювачем (пробіл або знак пунктуації)
bool IsDelimiter(char c)
{
    return isspace(static_cast<unsigned char>(c)) || ispunct(static_cast<unsigned char>(c));
}

// Підрахунок довжини найдовшого слова у літерному рядку
size_t MaxWordLength(const string& s)
{
    size_t maxLen = 0;
    size_t start = 0;
    size_t finish = 0;
    const size_t len = s.length();

    while (start < len)
    {
        // Пропускаємо всі пробіли та знаки пунктуації
        while (start < len && IsDelimiter(s[start]))
            start++;

        if (start >= len)
            break;

        finish = start;
        // Шукаємо кінець поточного слова
        while (finish < len && !IsDelimiter(s[finish]))
            finish++;

        size_t currentWordLen = finish - start;
        if (currentWordLen > maxLen)
            maxLen = currentWordLen;

        start = finish;
    }

    return maxLen;
}

// Знаходження першого слова з максимальною довжиною
string LongestWord(const string& s)
{
    size_t maxLen = 0;
    size_t bestStart = 0;
    size_t start = 0;
    size_t finish = 0;
    const size_t len = s.length();

    while (start < len)
    {
        while (start < len && IsDelimiter(s[start]))
            start++;

        if (start >= len)
            break;

        finish = start;
        while (finish < len && !IsDelimiter(s[finish]))
            finish++;

        size_t currentWordLen = finish - start;
        if (currentWordLen > maxLen)
        {
            maxLen = currentWordLen;
            bestStart = start;
        }

        start = finish;
    }

    if (maxLen == 0)
        return "";

    return s.substr(bestStart, maxLen);
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Length of max word: " << MaxWordLength(str) << endl;

    string longest = LongestWord(str);
    if (!longest.empty())
        cout << "Longest word: " << longest << endl;
    else
        cout << "No words found in the string." << endl;

    return 0;
}
