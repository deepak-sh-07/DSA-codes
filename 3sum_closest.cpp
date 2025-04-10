class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            int closest = INT_MAX/2;
            for(int i=0;i<n-2;i++){
                int lo = i+1,hi = n-1;
                while(lo<hi){
                    int curr = nums[i]+nums[lo]+nums[hi];
                    if(abs(curr-target) < abs(closest-target)){
                        closest = curr;
                    }
                    if(curr<target) lo++;
                    else if(curr>target) hi--;
                    else return curr;
                }
            }
            return closest;
        }
    };