
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
          int n = nums.size();
          vector<int> ans(n);
          vector<int> pre(n);
          vector<int> suff(n);
          pre[0] = 1;
          suff[n-1] = 1;
          int i = 1;
          int j = n-2;
          while(i<n && j>=0){
            pre[i] = pre[i-1]*nums[i-1];
            suff[j] = suff[j+1]*nums[j+1];
            i++;
            j--;
          }
          for(int k=0;k<n;k++){
            ans[k] = pre[k]*suff[k];
          }
          return ans;
        }
    };