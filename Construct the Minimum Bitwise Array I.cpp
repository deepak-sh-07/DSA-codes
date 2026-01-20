class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=1;j<nums[i];j++){
                if((j|(j+1))==nums[i]){
                    ans[i] = j;
                    flag = false;
                    break;
                }
            }
            if(flag==true) ans[i] = -1;
        }
        return ans;
    }
};
