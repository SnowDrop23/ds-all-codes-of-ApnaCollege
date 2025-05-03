//Problem link: https://leetcode.com/problems/reverse-string/description/

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>&s)
{
    int start = 0, end = s.size()-1;

    while(start < end)
    {
        swap(s[start++], s[end--]);
    }
}

int main()
{
    string str;
    cin >> str;

    vector<char> s(str.begin(), str.end());
    reverseString(s);

    for(char ch : s) cout << ch;
    cout << endl;
}
