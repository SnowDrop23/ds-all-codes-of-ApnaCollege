#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string &str)
{
    int start = 0, end = str.size()-1;

    while(start < end)
    {
        if(str[start++] != str[end--]) return false;
        /*else
        {
            start++;
            end--;
        }*/
    }
    return true;
}

int main()
{
    string str;
    cin >> str;

    cout << isPalindrome(str);
}
