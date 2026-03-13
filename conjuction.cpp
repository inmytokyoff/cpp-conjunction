#include <iostream>
#include <fstream>

using namespace std;

    bool checkStrLen(char stroka1[], char stroka2[])
    {
    int len1 = 0;
    while (stroka1[len1] != '\0' && len1 < 9) len1++;
        if (len1 > 8)
        {
        return false;
        }
    
    int len2 = 0;
    while (stroka2[len2] != '\0' && len2 < 9) len2++;
        if (len2 > 8)
        {
        return false;
        }
    return true;
    }

    bool checkSymbol(char stroka1[], char stroka2[]) {
    int len1 = 0;
    while (stroka1[len1] != '\0') len1++;
    
    for (int i = 0; i < len1; i++)
    {
        if (stroka1[i] != '0' && stroka1[i] != '1')
        {
            return false;
        }
    }
    
    int len2 = 0;
    while (stroka2[len2] != '\0') len2++;
    
    for (int i = 0; i < len2; i++) {
        if (stroka2[i] != '0' && stroka2[i] != '1')
        {
            return false;
        }
    }
    
    return true;
    }

    void addZero (char stroka[], int sdvig){
        for (int i = 7; i >= sdvig; i--)
            {
                stroka[i] = stroka[i - sdvig];
            }
        for (int i = 0; i < sdvig; i++)
            {
                stroka[i] = '0';
            }
        stroka[8] = '\0';
    }

    void conjuction(char stroka1[], char stroka2[], char stroka_result[]){
    for (int i = 0; i < 8; i++)
    {
        if (stroka1[i] == '1' && stroka2[i] == '1') {
            stroka_result[i] = '1';
        }
        else {
            stroka_result[i] = '0';
        }
    }
    stroka_result[8] = '\0';
    }

int main()
{
    
    char stroka1[9];
    char stroka2[9];
    char stroka_result[9];


    cout << "Enter string 1: ";
    cin >> stroka1;
    cout << "Enter string 2: ";
    cin >> stroka2;

    if(!checkStrLen(stroka1, stroka2)){
        cout << "Error. String must be 8 symbol." << endl;
        return 1;
    }

    if (!checkSymbol(stroka1, stroka2))
    {
        cout << "Error. String consist of 0 or 1." << endl;
        return 1;
    }

    ofstream OutFile1("stroka1.txt");
    OutFile1 << stroka1;
    OutFile1.close();

    ofstream OutFile2("stroka2.txt");
    OutFile2 << stroka2;
    OutFile2.close();

    ifstream InputFile1("stroka1.txt");
    InputFile1 >> stroka1;
    InputFile1.close();

    ifstream InputFile2("stroka2.txt");
    InputFile2 >> stroka2;
    InputFile2.close();

    int len1 = 0;
    int len2 = 0;

    while (stroka1[len1] != '\0') len1++;
    while (stroka2[len2] != '\0') len2++;
    
    int sdvig1 = 8 - len1;
    int sdvig2 = 8 - len2;

    addZero(stroka1, sdvig1);
    addZero(stroka2, sdvig2);

    conjuction(stroka1, stroka2, stroka_result);

    ofstream ResConj ("Result_of_Conjuction.txt");
    ResConj  << stroka_result;
    ResConj.close();

    cout << "\n";
    cout << "String 1: " << stroka1 << endl;
    cout << "String 2: " << stroka2 << endl;
    cout << "Result: " << stroka_result << endl;
    cout << "Result in file: Result_of_Conjuction" << endl;

    return 0;
}