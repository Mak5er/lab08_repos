// Lab_08_1_it.cpp
// Рева Максим
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (ітераційний спосіб)
// Варіант 23

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція пошуку індексу третьої за порядком коми
int FindThirdComma(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            count++;
            if (count == 3)
                return i;
        }
    }
    return -1;
}

// Функція заміни кожної коми парою зірочок "**"
char *Change(char *str)
{
    size_t len = strlen(str);
    char *tmp = new char[len * 2 + 1];
    char *t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i] != '\0')
    {
        if (str[i] == ',')
        {
            strcat(t, "**");
            t += 2;
            i++;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
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

    char *dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
