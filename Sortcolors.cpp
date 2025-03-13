class Solution {
    public:
        void sort(vector<int>& nums){
            int lo=0,hi = nums.size()-1,mid = 0;
            while(mid<=hi){
                if(nums[mid]==2){
                    swap(nums[mid],nums[hi]);
                    hi--;
                }else if(nums[mid]==0){
                    swap(nums[mid],nums[lo]);
                    lo++;
                    if(mid<lo) mid=lo;
                }else mid++;
            }
        }
        void sortColors(vector<int>& nums) {
            sort(nums);
        }
    };