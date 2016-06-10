#include <iostream>
#include "String.hpp"

using namespace std;

void f(char *);

int main()
{
    String s1;
    String s2;

    s1 += s2;
    s1 += 'a';
    s1 += "Hello";
    s2 = "Hello" + s1;

    f(s2);
    if (s2 > s1)
    {
        cout << s1 << endl;
    }
    if (s1 <= s2)
    {
        cout << s2 << endl;
    } if (!s1)
    {
         // true если строка пустая
         cin >> s1;
    }
    return 0;
}

void f(char * ch)
{

}
