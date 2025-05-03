//Problem Link: https://leetcode.com/problems/valid-palindrome/description/
#include <iostream>
#include <vector>
using namespace std;

bool isAlphaNum(char ch)
{
    if((ch >= '0' && ch <= '9') || 
    (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
        return true;
    else return false;
}

bool isPalindrome(string &str)
{
    int start = 0, end = str.size()-1;

    while(start < end)
    {
        if(!isAlphaNum(str[start]))
        {
            start++;
            continue;
        }
        if(!isAlphaNum(str[end]))
        {
            end--;
            continue;
        }
        if(tolower(str[start++]) != tolower(str[end--])) return false;
    }
    return true;
}

int main()
{
    string str;
    cin >> str;

    cout << isPalindrome(str);
}
