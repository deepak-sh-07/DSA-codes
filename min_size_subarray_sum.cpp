class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
      int n= nums.size();
      int len,minlen = INT_MAX;
      int sum=0;
      int i=0,j=0;
      while(j<n){
        sum = sum+nums[j];
        while(sum>=target){
          len = j-i+1;
          minlen = min(len,minlen);
          sum = sum-nums[i];
          i++;
        }
        j++;
      } 
      if(minlen==INT_MAX) return 0;
      return minlen;
        }
    };