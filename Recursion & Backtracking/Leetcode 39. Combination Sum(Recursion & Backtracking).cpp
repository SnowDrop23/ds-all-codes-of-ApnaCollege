#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s; // to store unique combinations

void get_all_combination(vector<int>& arr, int idx, int tar,
                         vector<vector<int>>& ans, vector<int>& combin) {
    if (idx == arr.size() || tar < 0)
        return;

    if (tar == 0) {
        if (s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    // include current element and stay at idx
    combin.push_back(arr[idx]);
    get_all_combination(arr, idx, tar - arr[idx], ans, combin);

    // include current element and move to next idx
    get_all_combination(arr, idx + 1, tar - arr[idx], ans, combin);

    // backtrack
    combin.pop_back();

    // exclude current element
    get_all_combination(arr, idx + 1, tar, ans, combin);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;

    get_all_combination(arr, 0, target, ans, combin);

    return ans;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = combinationSum(arr, target);

    cout << "\nUnique combinations that sum to " << target << ":\n";
    if (result.empty()) {
        cout << "No combination found.\n";
    } else {
        for (auto& comb : result) {
            for (int num : comb)
                cout << num << " ";
            cout << "\n";
        }
    }

    return 0;
}
