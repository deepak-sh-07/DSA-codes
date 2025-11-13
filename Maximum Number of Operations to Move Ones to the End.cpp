class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ans = 0;
        int count = 0;
        int i=0;
        while(i<n-1){
            if(s[i]=='1'){
                count++;
                if(s[i+1]=='0'){
                    ans += count;
                    while(i<n-1 && s[i+1]=='0') i++;
                } 
            }
            i++;
        }
        return ans;
    }
};
