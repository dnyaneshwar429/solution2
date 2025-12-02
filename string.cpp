// 1)	Implement basic string operations such as length calculation, copy, reverse, and concatenation using character single dimensional arrays without using built-in string library functions.
#include <iostream>
using namespace std;

int length(char str[])
{

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}
void reverse(char str1[])
{
    int len = length(str1);

    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        char temp = str1[i];
        str1[i++] = str1[j];
        str1[j--] = temp;
    }
}
void CopyStr(char copystr[], char str1[])
{
    int len = length(str1);

    for (int i = 0; i < len; i++)
    {
        copystr[i] = str1[i];
    }
    copystr[len] = '\0';
}
void Concatinate(char str1[], char str2[])
{
    int len1 = length(str1);
    int len2 = length(str2);

    for (int i = 0; i < len2; i++)
    {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
}
int main()
{

    char str1[100], str2[100], copystr[100];

    cout << "Enter string 1 : ";
    cin >> str1;

    cout << "Enter string 2 : ";
    cin >> str2;

    cout << "Length of the string is :" << length(str2) << endl;

    CopyStr(copystr, str1);
    cout << "Copied string copystr: " << copystr << endl;

    Concatinate(copystr, str2);
    cout << "concatinated string copystr + str2: " << copystr << endl;

    reverse(str1);
    cout << "Reversed string str1 : " << str1 << endl;
    return 0;
}
