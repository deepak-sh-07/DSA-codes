class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==2) return true;
        int i=0,j=k;
        while(i<=n-k*2){
            int a = i,b = j;
            while(a<j-1){
                if(nums[a]<nums[a+1] && nums[b]<nums[b+1]){
                    a++;
                    b++;
                }else{
                    i++;
                    j = i+k;
                    break;
                }
                if(a==j-1) return true;
            }
            if(a==j-1) return true;
        }
        return false;
    }
};
