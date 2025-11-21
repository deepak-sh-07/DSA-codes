class Solution {
public:
    int countPalindromicSubsequence(string s) {
      int n = s.length();
      unordered_set<char> letters;
      for(int i=0;i<n;i++){
        letters.insert(s[i]);
      } 
      int ans = 0; 
      for(auto letter:letters){
        int first= -1;
        int last = -1;
        for(int i=0;i<n;i++){
            if(s[i]==letter){
                if(first==-1){
                first = i;
            }
            last = i;
            }
            
        }
        unordered_set<char> st;
        for(int mid=first+1;mid<last;mid++){
            st.insert(s[mid]);
        }
        ans += st.size();
      }
      return ans;
    }
};
