class Solution {
    public:
        string smallestPalindrome(string s) {
            map<char, int> mp;
            for (int i = 0; i < s.length(); i++) {
                mp[s[i]]++;
            }
            string half = "";
            char middle = '0';
            for (auto ele : mp) {
                if (ele.second % 2 != 0) {
                    middle = ele.first;
                }
                half += string(ele.second / 2, ele.first);
            }
            string result = half;
            if (middle != '0') {
                result += middle;
            }
            reverse(half.begin(), half.end());
            result += half;
    
            return result;
        }
    };