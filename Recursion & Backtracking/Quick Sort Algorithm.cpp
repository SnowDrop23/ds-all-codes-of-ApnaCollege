#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int st, int end)
{
    int idx = st - 1, pivot = a[end];
    for(int j = st; j < end; j++)
    {
        if(a[j] <= pivot)
        {
            idx++;
            swap(a[j], a[idx]);
        }
    }
    idx++;
    swap(a[end], a[idx]);
    return idx; // ✅ return pivot index
}

void quick_sort(vector<int> &a, int st, int end)
{
    if(st < end)
    {
        int pivIdx = partition(a, st, end);

        quick_sort(a, st, pivIdx-1);
        quick_sort(a, pivIdx+1, end);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    quick_sort(a, 0, n-1);
    for(int i : a) cout << i << " ";
}
