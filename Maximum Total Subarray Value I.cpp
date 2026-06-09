class Solution {
public:
    typedef long long ll;
    long long maxTotalValue(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        int n = nums.size();
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        for(int i=0;i<n;i++){
                maxi = max(maxi,(ll)nums[i]);
                mini = min(mini,(ll)nums[i]);
                
        }
        ll ans = (maxi-mini)*k;
        return ans;
    }
};
