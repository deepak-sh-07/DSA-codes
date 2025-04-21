class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
    
            int size = 0, prev = -1;
    
            for(int i=0;i<nums.size();i++) {
                if(nums[i] >= prev) {
                    prev = nums[i];
                    size++;
                }
            }
    
            return size;
        }
    };