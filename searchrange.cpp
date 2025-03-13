class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
          int n = nums.size();
    
          int lo = 0,hi = n-1;
          bool flag = false;
          int mid;
          while(lo<=hi){
             mid = (lo+hi)/2;
            if(nums[mid]==target){
                flag = true;
                break;
            }else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
          } 
          if(flag==false) return {-1,-1};
          lo = mid,hi = mid;
          while(lo>0 && nums[lo-1]==target) lo--;
          while(hi<n-1 && nums[hi+1]==target) hi++;
          return {lo,hi}; 
        }
    };