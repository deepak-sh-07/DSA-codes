class Solution {
    public:
        void expand(string s,int l,int r,int &bleft,int &bright){
            while(l>=0 && r<s.length() && s[l]==s[r]){
                l--;
                r++;
            }
            l++;
            r--;
            if(r-l+1>bright-bleft+1){
                bleft = l;
                bright = r;
            }
        }
        string longestPalindrome(string s) {
            int bleft = 0;
            int bright = 0;
            for(int i=0;i<s.length();i++){
                expand(s,i,i,bleft,bright);//odd
                expand(s,i,i+1,bleft,bright);//even
            }
            return s.substr(bleft,bright-bleft+1);
        }
    };//leetcode-5