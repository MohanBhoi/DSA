#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            int left = lower_bound(arr.begin() + l, arr.begin() + r + 1, x) - arr.begin();

            int right = upper_bound(arr.begin() + l, arr.begin() + r + 1, x) - arr.begin() - 1;

            if (left <= right && left <= r && arr[left] == x) {
                ans.push_back(right - left + 1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 4, 5, 5, 5, 8};
    vector<vector<int>> queries = {
        {0, 7, 5},
        {1, 2, 2},
        {0, 3, 7}
    };

    vector<int> result = sol.countXInRange(arr, queries);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
