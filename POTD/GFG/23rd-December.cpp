#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries){
        vector<int>ans;
        sort(arr.begin(),arr.end());
        
        for(auto &it:queries){
            int a=it[0],b=it[1];
            // int count=0;
            // for(int i=a;i<=b;i++){
            //     for(int j=0;j<arr.size();j++){
            //         if(arr[j]==i) count++;
            //     }
            // }
            // ans.push_back(count);
            
            int left=lower_bound(arr.begin(),arr.end(),a)-arr.begin();
            int right=upper_bound(arr.begin(),arr.end(),b)-arr.begin();

            ans.push_back(right-left);            
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 3, 5, 7, 9, 3, 5};
    vector<vector<int>> queries = {
        {1, 5},
        {4, 8},
        {10, 20}
    };

    vector<int> ans= sol.cntInRange(arr,queries);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;

}