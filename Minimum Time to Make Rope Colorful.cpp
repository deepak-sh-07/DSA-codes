class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        int i=1;
            while(i<n){
            if(colors[i]==colors[i-1]){
                int sum = neededTime[i-1];
                int maxi = max(neededTime[i],neededTime[i-1]);
                while(i<n && colors[i]==colors[i-1]){
                    sum += neededTime[i];
                    maxi = max(neededTime[i],maxi);
                    i++;
                }
                ans =ans+sum-maxi;
            }
            i++;
        }
        return ans;
    }
};
