class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i]+nums[i-1];
        }
        for(int i=0;i<n-1;i++){
            int num = nums[n-1]-nums[i]-nums[i];
            if(num%2==0) total++;
        }
        return total;
    }
};
