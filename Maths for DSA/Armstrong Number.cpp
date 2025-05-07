
#include <iostream>

using namespace std;

int isArmstrong(int n)
{
    int copyN = n;
    int sumOfCubes = 0;

    while(n != 0)
    {
        int digit = n % 10;
        sumOfCubes += (digit * digit * digit);

        n /= 10;
    }
    return sumOfCubes == copyN;
    


}


int main()
{
    int n;
    cin >> n;

    if(isArmstrong(n)) cout << "is an armstrong number\n";
    else cout << "Not an armstrong number\n";

}
