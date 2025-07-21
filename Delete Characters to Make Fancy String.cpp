class Solution {
public:
    string makeFancyString(string s) {
        string x = "";
        x = x+s[0];
        int count = 1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                count++;
                if(count<=2) x += s[i];
            }else{
                x += s[i];
                count = 1;
            }
        }
        return x;
    }
};
