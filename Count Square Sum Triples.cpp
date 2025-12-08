class Solution {
public:
    int countTriples(int n) {
      int ans = 0;
      for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            int num1 = i*i+j*j;
            int num = sqrt(num1);
            if(num>n) break;
            if(num*num==num1) ans += 2;
        }
      } 
      return ans;
    }
};
