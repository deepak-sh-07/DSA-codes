class Solution {
    public:
        int count(int n){
            int c = 0;
            while(n>0){
                c++;
                n=n/10;
            }
            return c;
        }
        int findNumbers(vector<int>& nums) {
            int n = nums.size();
            int c = 0;
            for(int i=0;i<n;i++){
                if(count(nums[i])%2==0) c++;
            }
            return c;
        }
    };