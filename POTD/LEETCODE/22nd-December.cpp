#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
    int minDeletionSize(vector<string>& strs) {

       int rows=strs.size();
       int cols=strs[0].size();

       vector<int>dp(cols,1);
       int check=1;

       for(int i=0;i<cols;i++){
        for(int j=0;j<i;j++){

            bool valid=true;
            for(int k=0;k<rows;k++){
                if(strs[k][j]>strs[k][i]){
                    valid=false;
                    break;
                }
            }

            if(valid){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        check=max(check,dp[i]);
       }

       return cols-check;
    }
};

int main(){
    Solution obj;
    vector<string> strs={"babca","bbazb"};

    cout << "Output: " << obj.minDeletionSize(strs) << endl;
    return 0;
}