class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
        long long i=0,j=nums.size()-2;
        long long med = 0;
        while(i<j){
            med += nums[j];
            j = j-2;
            i++;
        }
        return med;
    }
};
