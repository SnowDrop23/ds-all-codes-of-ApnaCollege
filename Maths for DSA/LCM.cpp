
#include <iostream>
using namespace std;

/*int gcd(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    return a;
}*/

int gcdRec(int a, int b)
{
    if(b == 0) return a;
    return gcdRec(b, a%b);
}
int lcm(int a, int b)
{
    int gcd = gcdRec(a, b);

    return (a * b) / gcd;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << lcm(a, b) << endl;
    //cout << gcdRec(a, b) << endl;
}
