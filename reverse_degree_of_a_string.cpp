class Solution {
    public:
        int reverseDegree(string s) {
          unordered_map<char,int> pq;
            int total = 26;
            for(char ch = 'a';ch<='z';ch++){
                pair<char,int> p;
                p.first = ch;
                p.second = total;
                pq.insert(p);
                total--;
            }
            int sum = 0;
            for(int i=0;i<s.length();i++){
                int x = pq[s[i]];
                sum = sum +x*(i+1);
            }
            return sum;
        }
    };