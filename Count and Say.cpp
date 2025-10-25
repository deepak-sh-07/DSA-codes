class Solution {
public:
    string RLE(string s){
        int count = 1;
        int n = s.length();
        int i = 1;
        string ans = "";
        while(i<=n){
            if(i==n){
                string x = to_string(count);
                ans = ans + x +s[i-1];
                return ans;
            }
            if(s[i]==s[i-1]){
                count++;
            }else{
                string x = to_string(count);
                ans = ans + x +s[i-1];
                count = 1;
            }
            i++;
        }
        return s;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = "1";
        int i=2;
        string ans;
        while(i<=n){
            ans = RLE(s);
            s = ans;
            i++;
        }
        return ans;
    }
};
