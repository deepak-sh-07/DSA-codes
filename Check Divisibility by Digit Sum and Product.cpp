class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int sum = 0;
        int prod = 1;
            while(m>0){
            int rem = m%10;
            sum += rem;
            prod *= rem;
            m = m/10;
        }
        sum += prod;
        if(n%sum==0) return true;
        return false;
    }
};
