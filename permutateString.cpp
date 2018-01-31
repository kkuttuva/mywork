#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void permutate(vector<string> s, int pos, int len)
{
    if (pos == len)
    {
        for (vector<string>::iterator it = s.begin(); it != s.end(); it++)
            cout<<*it<<" ";
        cout << "\n";
        return;
    }

    for (int i = pos; i < len; i++)
    {
        string c = s[pos];
        s[pos] = s[i];
        s[i] = c;

        permutate(s, pos + 1, len);

        c = s[pos];
        s[pos] = s[i];
        s[i] = c;
    }
}

int main()
{
    string s = "abc";
    string s1 = "def";
    string s2 = "ghi";

    vector<string> v;

    v.push_back(s);
    v.push_back(s1);
    v.push_back(s2);
    permutate(v, 0, s.length());
    return 0;
}
