class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int len = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(len==-1) len = 0;
                else {
                    if(len<k) return false;
                    len = 0;
                }
            }else{
                if(len!=-1) len++;
            }
        }
        return true;
    }
};
