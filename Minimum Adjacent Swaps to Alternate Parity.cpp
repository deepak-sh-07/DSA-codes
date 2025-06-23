class Solution {
public:
    int eswaps(vector<int>& nums) {
        int n = nums.size();
        int swaps = 0;
        int pos = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                swaps += abs(i - pos);
                pos += 2; 
            }
        }
        return swaps;
    }

    int oswaps(vector<int>& nums) {
        int n = nums.size();
        int swaps = 0;
        int pos = 0;  

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                swaps += abs(i - pos);
                pos += 2; 
            }
        }
        return swaps;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        if (abs(odd - even) > 1)
            return -1;
           if(n%2==1){
            if(even>odd) return eswaps(nums);
            else return oswaps(nums);
           }
        
        return min(eswaps(nums),oswaps(nums));
    }
};
