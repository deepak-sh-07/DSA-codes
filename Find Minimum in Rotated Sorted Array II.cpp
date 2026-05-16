class Solution {
public:
    int search(int lo,int hi,vector<int>& nums){
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(nums[lo]<nums[hi]) return nums[lo];
            if(nums[mid]==nums[hi]){
                int first = search(lo,mid,nums);
                int second = search(mid+1,hi,nums);
                return min(first,second);
            }
            if(nums[mid]>nums[hi]) lo = mid+1;
            else hi = mid;
        }
        return nums[lo];
    }
    int findMin(vector<int>& nums) {
        return search(0,nums.size()-1,nums);
    }
};
