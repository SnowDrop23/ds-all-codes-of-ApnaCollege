//Problem Link: https://leetcode.com/problems/permutation-in-string/description/

#include <iostream>
//#include <algorithm>
using namespace std;


bool isFreqSame(int freq1[], int freq2[])
{
    for(int i = 0; i < 26; i++)
    {
        if(freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int freq[26] = {0};

    for(int i = 0; i < s1.size(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    int windSize = s1.size();
    
    for(int i = 0; i < s2.size(); i++) 
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        while(windIdx < windSize && idx < s2.size())
        {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if(isFreqSame(freq, windFreq)) return true;
    }
    return false;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    bool result = checkInclusion(str1, str2);

    cout << ((result > 0) ? "true" : "false");
    
    

    
}
