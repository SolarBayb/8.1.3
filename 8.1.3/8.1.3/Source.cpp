#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* ChangeSim(char* cs, const char s)
{
    char* t = new char[strlen(cs)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;
    while (p = strchr(cs + pos1, s))
    {
        pos2 = p - cs + 1;
        strncat(t, cs + pos1, pos2 - pos1 - 1);
        strcat(t, "**");
        pos1 = pos2;
    }

    strcat(t, cs + pos1);
    strcpy(cs, t);
    return t;
}



int CountSim(char* s, const char* cs)
{
    int k = 0,
        pos = 0;
    char* t;
    while (t = strpbrk(s + pos, cs))
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char cs[201];

    cout << "Ввести: ";

    cin.getline(cs, 200); cout << endl;

    char s[] = "+-=";

    cout << "К-сть:  " << CountSim(cs, s) << endl;

    char* dest = new char[151];
    ChangeSim(cs, s[0]);
    ChangeSim(cs, s[1]);
    dest = ChangeSim(cs, s[2]);

    cout << "Резултат: " << dest << endl;

    return 0;
}