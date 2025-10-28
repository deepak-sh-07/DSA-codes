class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int cnt = 0, maxflip = 0;
        for(int i=0;i<n;i++){
            maxflip = max(maxflip, flips[i]);
            if(maxflip==i+1)cnt++;
        }
        return cnt;
    }
};
