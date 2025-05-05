//Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
#include <iostream>

using namespace std;

string removeOccurrences(string &str, string &part)
{
    while(str.size() > 0 && str.find(part) < str.size())
    {
        str.erase(str.find(part), part.size());
    }
    return str;
}

int main()
{
    string str, part;
    cin >> str >> part;

    cout << removeOccurrences(str, part);

    
}
