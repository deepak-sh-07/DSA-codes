class Solution {
public:
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        for(int i=0;i<nums.size();i++){
            if(i<2){
                b.push_back(nums[i]);
                continue;
            }
            if(isPrime(i)==true) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        long long suma = 0;
        long long sumb = 0;
        for(int i=0;i<a.size();i++){
            suma+= a[i];
        }
        for(int i=0;i<b.size();i++){
            sumb+= b[i];
        }
        return abs(suma-sumb);
    }
};
