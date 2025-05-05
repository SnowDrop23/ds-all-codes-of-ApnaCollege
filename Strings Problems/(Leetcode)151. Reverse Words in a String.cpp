
#include <iostream>
#include <algorithm>
using namespace std;


string reverseString(string str)
{
    int n = str.size();
    string ans = "";

    reverse(str.begin(), str.end());

    for(int i = 0; i < n; i++)
    {
        string word = "";
        while(i < n && str[i] != ' ')
        {
            word += str[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.size() > 0) ans += " " + word;

    }

    return ans.substr(1); // Return the string "ans" starting from index 1, i.e., skip the first character which is space(" ").



}

int main ()
{
    string str;
    getline(cin, str); // reads full sentence input with spaces.

    string ans = reverseString(str);
    cout << ans << endl;
}
