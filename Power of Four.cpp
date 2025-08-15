class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        long long num = 1;
        for(int i=0;i<15;i++){
            num *= 4;
            if(num==n) return true;
        }
        return false;
    }
};
