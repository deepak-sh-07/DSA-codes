class Solution {
public:
    int mod = 1000000007;
    int numSub(string s) {
        long long count = 0;
        int n = s.length();
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                long long total = 0;
               while(i<n && s[i]=='1'){
                total++;
                i++;
               } 
               count = (count+(total*(total+1)/2)%mod)%mod;
            }
            i++;
        }
        return count;
    }
};
