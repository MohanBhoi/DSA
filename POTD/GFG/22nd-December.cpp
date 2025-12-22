#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n=arr.size();
        int m=arr[0].size();
        
        int ans=-1;
        // int found=0;
        // for(int j=0;j<n;j++){
        //     vector<int>v=arr[j];
        //     int count=0;
        //     for(int i=0;i<m;i++){
        //         if(v[i]==1) count++;
        //     }
        //     if(count>found){
        //         found=count;
        //         ans=j;
        //     }
        // }
        
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(arr[i][j]==1){
                ans=i;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> arr={
        {0,0,1,1},
        {0,0,0,0},
        {0,0,0,1},
        {0,1,1,1}
    };

    Solution obj;
    cout << obj.rowWithMax1s(arr) << endl;
    return 0;
};