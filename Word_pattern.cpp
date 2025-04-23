class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char,string> mp;
            unordered_map<string,char> cp;
            int n = pattern.length();
            int m = count(s.begin(), s.end(), ' ') +1;
            if(m!=n) return false;
            stringstream str(s);
            string word;
            int i=0;
            while(str>>word){
                if(mp.find(pattern[i])!=mp.end()){
                    if(mp[pattern[i]]!=word) return false;
                }else{
                    mp.insert({pattern[i],word});
                }
                i++;
            }
            string wor;
            stringstream st(s);
            i=0;
            while(st>>wor){
                if(cp.find(wor)!=cp.end()){
                    if(cp[wor]!=pattern[i]) return false;
                }else{
                    cp.insert({wor,pattern[i]});
                }
                i++;
            }
            return true;
        }
    };