// Lab_08_1_rec.cpp
// Рева Максим
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (рекурсивний спосіб)
// Варіант 23

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція рекурсивного пошуку індексу третьої за порядком коми
int FindThirdComma(const char* str, int count = 0, int i = 0)
{
    if (str[i] == '\0')
        return -1;
    if (str[i] == ',')
    {
        count++;
        if (count == 3)
            return i;
    }
    return FindThirdComma(str, count, i + 1);
}

// Функція рекурсивної заміни кожної коми парою зірочок "**"
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0')
    {
        if (str[i] == ',')
        {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 1);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int index = FindThirdComma(str, 0, 0);
    if (index != -1)
        cout << "Index of third comma: " << index << endl;
    else
        cout << "Third comma not found (less than 3 commas)" << endl;

    char* dest1 = new char[strlen(str) * 2 + 1];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
