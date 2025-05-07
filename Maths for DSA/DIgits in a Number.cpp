
#include <iostream>
#include <vector>
using namespace std;

void printDigits(int n)
{
    int sum = 0, count = 0;

    while(n != 0)
    {
        int digits = n % 10;
        sum += digits;
        count++;

        n /= 10;
    }
    cout << "Number of digits: " << count << endl;
    cout << "Sum : " << sum << endl;
    


}


int main()
{
    int n;
    cin >> n;

    printDigits(n);

}
