//Question Link: https://leetcode.com/problems/powx-n/description/
//Date: 28 January 2025
#include<iostream>
using namespace std;

double(myPow(double x, int n))
{
    //corner cases, doesn't necessary to write, without these code will run perfectly
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;
    long binForm = n;
    if(n < 0)
    {
        x = 1/x;
        binForm = -binForm;
    }
    //long binForm = n;
    double ans = 1;

    while(binForm > 0)
    {
        if(binForm % 2 == 1) ans *= x;
        x *= x;
        
        binForm /= 2;
    }
    cout << endl;
    return ans;
}


int main ()
{
    int n; //power
    double x; //base
    cout << "Enter power and base: ";
    cin >> n >> x;
    double ans = myPow(x, n);
    cout << ans << endl;
    
    return 0;
    
}
