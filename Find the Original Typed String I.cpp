class Solution {
public:
    int possibleStringCount(string word){
       int count = 0;
       int total = 1;
       int n = word.length();
       for(int i=1;i<n;i++){
        if(i==n-1){
         if(word[i]==word[i-1]) count++;
          total += count;  
        }
        else if(word[i]==word[i-1]) count++;
        else{
            total += count;
            count = 0;
        }
       }
       return total;
    }
};
