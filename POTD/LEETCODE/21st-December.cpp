#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int del=0;

        vector<bool>sorted(n-1,false);

        for(int c=0;c<m;c++) {
            bool d=false;
            for(int i=0;i<n-1;i++)
                if(!sorted[i] && strs[i][c]>strs[i + 1][c]){ 
                    d=true; 
                    break; 
                }

            if (d){
                del++; 
                continue; 
            }

            for (int i=0;i<n-1;i++){
                if (strs[i][c]<strs[i+1][c]) sorted[i] = true;
            }
        }
        return del;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"xc","yb","za"};
    cout << sol.minDeletionSize(strs) << endl;
    return 0;
}