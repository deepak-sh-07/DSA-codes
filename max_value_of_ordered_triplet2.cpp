class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            int pre[n];
            int suff[n];
            int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                maxi = max(maxi,nums[i]);
                pre[i] = maxi;
            }
            maxi = INT_MIN;
            for(int i=n-1;i>=0;i--){
                maxi = max(maxi,nums[i]);
                suff[i] = maxi;
            }
            long long sum = 0;
            for(int i=1;i<n-1;i++){
                long long int x = (pre[i-1]-nums[i]);
                x = x*suff[i+1];
                sum = max(sum,x);
            }
            return sum;
        }
    };//2874