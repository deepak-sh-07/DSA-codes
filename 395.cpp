class Solution {
    public:
        #define MAX 26
        bool atLeastK(int freq[], int k)
        {
            for (int i = 0; i < MAX; i++) {
                if (freq[i] != 0 && freq[i] < k)
                    return false;
            }
        
            return true;
        }
    
        void setZero(int freq[])
        {
            for (int i = 0; i < MAX; i++)
                freq[i] = 0;
        }
    
    
        int longestSubstring(string s, int k) {
            int n=s.length();
            int maxLen = 0;
     
            int freq[MAX];
            for (int i = 0; i < n; i++) {
                setZero(freq);
                for (int j = i; j < n; j++) {
                    freq[s[j] - 'a']++;
                    if (atLeastK(freq, k)) {
                        maxLen = max(maxLen, j - i + 1);
                    }
                }
            }
        
            return maxLen;
        }
    };