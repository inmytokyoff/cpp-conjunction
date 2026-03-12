#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    
    char stroka1[9];
    char stroka2[9];
    char stroka_result[9];

    cout << "Введите первую строку: ";
    cin >> stroka1;
    cout << "Введите вторую строку: ";
    cin >> stroka2;

    int len1 = 0;
    while (stroka1[len1] != '\0' && len1 < 9) len1++;
    if (len1 > 8) 
    {
        cout << "Ошибка. Длина строки больше 8." << endl;
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        if (i < len1) {
            if (stroka1[i] != '0' && stroka1[i] != '1') {
                cout << "Ошибка. Ввод только 0 и 1." << endl;
                return 1;
            }
        }
    }

    int sdvig1 = 8 - len1;
    for (int i = 7; i >= sdvig1; i--)
    {
        stroka1[i] = stroka1[i - sdvig1];
    }
    for (int i = 0; i < sdvig1; i++)
    {
        stroka1[i] = '0';
    }
    stroka1[8] = '\0';

    int len2 = 0;
    while (stroka2[len2] != '\0' && len2 < 9) len2++;
    if (len2 > 8)  
    {
        cout << "Ошибка. Длина строки больше 8." << endl;
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        if (i < len2) {
            if (stroka2[i] != '0' && stroka2[i] != '1') {
                cout << "Ошибка. Ввод только 0 и 1." << endl;
                return 1;
            }
        }
        else {
            stroka2[i] = '0';
        }
    }
    stroka2[8] = '\0';

    for (int i = 0; i < 8; i++) {
        if (stroka1[i] == '1' && stroka2[i] == '1') {
            stroka_result[i] = '1';
        }
        else {
            stroka_result[i] = '0';
        }
    }
    stroka_result[8] = '\0';

    cout << "\n";
    cout << "Строка 1: " << stroka1 << endl;
    cout << "Строка 2: " << stroka2 << endl;
    cout << "Результат: " << stroka_result << endl;

    return 0;
}