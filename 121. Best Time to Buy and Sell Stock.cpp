//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&price)
{
    int maxProfit = 0, bestBuy = price[0];
    for(int i = 1; i < price.size(); i++)
    {
        if(price[i] > bestBuy) 
            maxProfit = max(maxProfit, price[i] - bestBuy);
        bestBuy = min(bestBuy, price[i]);

    }
    return maxProfit;
}


int main ()
{
    int n;
    cout << "Enter array size:";
    cin >> n;
    cout << "Enter prices of a given stock: ";
    vector<int>price(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    cout << maxProfit(price);

    return 0;
    
}
