class Solution {
public:
    string largestEven(string s) {
        while(s.length()>0){
            int last = s[s.length()-1]-'0';
            if(last%2==0) return s;
            s.pop_back();
        }
        return s;
    }
};©leetcode
