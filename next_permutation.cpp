class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
           int idx = -1;
           int x = nums.size();
           for(int  i=x-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }}
            if(idx==-1){
                reverse(nums.begin(),nums.end());
                return;
            }
           reverse(nums.begin()+idx+1,nums.end());
           int j = -1;
           for(int i=idx+1;i<x;i++){
            if(nums[i]>nums[idx]){
                j = i;
                break;
            }
           }
            int temp = nums[idx];
            nums[idx]=nums[j];
            nums[j]=temp;
            return;
           
           
        }
    };