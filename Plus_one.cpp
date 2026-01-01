class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n= digits.size();
       int i=n-1, carry=1;
       while(i>=0){
        int sum = digits[i]+carry;
        digits[i]=sum%10;
        carry = sum/10;
        if(carry==0) return digits;
        i--;
       }
       if(carry==1){
        digits[0]=1;
        digits.push_back(0);
       }
       return digits;
    }
};
