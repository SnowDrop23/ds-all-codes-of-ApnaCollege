
#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars)
{
    int n = chars.size();
    int idx = 0;

    for(int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch)
        {
            count++;
            i++;
        }

        if(count == 1) chars[idx++] = ch;
        else
        {
            chars[idx++] = ch;
            string str = to_string(count);

            for(char digit : str) chars[idx++] = digit;
        }
        i--;
    }

    chars.resize(idx);
    return idx;
}


int main ()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<char>s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int res = compress(s);
    cout << "Length of new array after compressed: " << res << endl;
}
