class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int x : nums) {
            vector<int> temp = dp;
            for (int r = 0; r < 3; r++) {
                int newSum = temp[r] + x;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }

        return dp[0]; 
    }
};
class Solution {
public:
    int f(int i,vector<int>& nums,int sum){
        if(i==nums.size()){
            if(sum%3==0) return sum;
            else return 0;
        }
        int pick = f(i+1,nums,sum+nums[i]);
        int notpick = f(i+1,nums,sum);
        return max(pick,notpick);
    }
    int maxSumDivThree(vector<int>& nums) {
        return f(0,nums,0);
    }
};
