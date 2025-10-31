class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0,r=0,maxf=0,maxl=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            maxf = max(maxf,mp[s[r]]);
            while(r-l+1-maxf>k){
                mp[s[l]]--;
                int maxf2 = 0;
                for(auto ele:mp){
                    maxf2 = max(maxf2,ele.second);
                }
                maxf = maxf2;
                l++;
            }
            if(r-l+1-maxf<=k){
                maxl = max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;
    }
};
