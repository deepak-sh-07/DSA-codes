class Solution {
    public:
        int longestBeautifulSubstring(string word) {
            int maxLength = 0, left = 0, vowel = 1;
    
            for(int i=1; i<word.size(); i++)
            {
                if(word[i] < word[i-1])
                {
                    vowel = 1;
                    left = i;
                }
    
                else if(word[i-1] < word[i])
                {
                    vowel++;
                }
    
                if(vowel == 5)
                {
                    maxLength = max(maxLength, i - left + 1);
                }
            }
            return maxLength;
        }
    };