class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            int n = cost.size();
            int mini = cost[0];
            vector<int> ans(n);
            ans[0] = cost[0];
            for(int i=1;i<n;i++){
                mini = min(mini,cost[i]);
                ans[i] = mini;
            }
            return ans;
        }
    };