class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        int i=0;
        while(n>2){
            int first = s[i]-'0';
            int second = s[i+1]-'0';
            first = (first+second)%10;
            s[i] = first+'0';
            i++;
            if(i==n-1){
                n--;
                i=0;
            }
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};
