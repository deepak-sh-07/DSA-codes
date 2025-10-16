class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;

        for (int n : nums) {
            int r = ((n % value) + value) % value; 
            mp[r]++;
        }

        int mex = 0;
        while (true) {
            int r = mex % value;
            if (mp[r] > 0)
                mp[r]--;
            else
                return mex;
            mex++;
        }
    }
};
