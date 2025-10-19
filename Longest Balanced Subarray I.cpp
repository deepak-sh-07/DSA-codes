class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            int o=0,e =0;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                    if(nums[j]%2==0) e++;
                    else o++;
                    mp[nums[j]]++;
                }
                if(e==o) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};
