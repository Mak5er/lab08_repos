// Lab_08_1_string.cpp
// Рева Максим
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку (використання стандартних функцій для рядків string)
// Варіант 23

#include <iostream>
#include <string>

using namespace std;

// Пошук індексу третьої за порядком коми за допомогою string::find
size_t FindThirdComma(const string& s)
{
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos)
    {
        count++;
        if (count == 3)
            return pos;
        pos++;
    }
    return string::npos;
}

// Заміна кожної коми парою зірочок "**" за допомогою string::find та string::replace
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find(',', pos)) != string::npos)
    {
        s.replace(pos, 1, "**");
        pos += 2;
    }
    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    size_t index = FindThirdComma(str);
    if (index != string::npos)
        cout << "Index of third comma: " << index << endl;
    else
        cout << "Third comma not found (less than 3 commas)" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
