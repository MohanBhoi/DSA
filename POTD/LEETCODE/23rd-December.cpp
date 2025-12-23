#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        int bestPart=0;
        int ans=0;

        for(auto it:events){
            int start=it[0],end=it[1],val=it[2];
            while(!pq.empty() && pq.top().first<start){
                bestPart=max(bestPart, pq.top().second);
                pq.pop();
            }
            ans=max(ans,bestPart+val);

            pq.push({end,val});
        }

        return ans;
    }
};


int main(){
    Solution obj;
    vector<vector<int>> events = {{1,5,3},{1,5,1},{6,6,5}};
    cout << "Output:" << obj.maxTwoEvents(events) << endl;
    return 0;

}