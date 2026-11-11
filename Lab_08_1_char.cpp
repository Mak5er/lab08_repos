// Lab_08_1_char.cpp
// Рева Максим
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (використання стандартних функцій для рядків char[])
// Варіант 23

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Пошук індексу третьої за порядком коми за допомогою стандартної функції strchr
int FindThirdComma(const char* s)
{
    int count = 0;
    const char* p = s;
    while ((p = strchr(p, ',')) != nullptr)
    {
        count++;
        if (count == 3)
            return static_cast<int>(p - s);
        p++;
    }
    return -1;
}

// Заміна кожної коми парою зірочок "**" за допомогою стандартних функцій C (strchr, strncat, strcat, strcpy)
char* Change(char* s)
{
    char* t = new char[strlen(s) * 2 + 1];
    char* p;
    int pos1 = 0;
    int pos2 = 0;
    *t = '\0';

    while ((p = strchr(s + pos1, ',')) != nullptr)
    {
        pos2 = static_cast<int>(p - s);
        strncat(t, s + pos1, pos2 - pos1);
        strcat(t, "**");
        pos1 = pos2 + 1;
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main()
{
    char str[201];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int index = FindThirdComma(str);
    if (index != -1)
        cout << "Index of third comma: " << index << endl;
    else
        cout << "Third comma not found (less than 3 commas)" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
