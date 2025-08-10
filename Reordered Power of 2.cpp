class Solution {
public:
    vector<int> Cpower(int n){
        vector<int> count(10,0);
        while(n>0){
            count[n%10]++;
            n = n/10;
        }
        return count;
    }
    bool check(vector<int>parray,vector<int>power){
        for(int i=0;i<10;i++){
            if(parray[i]!=power[i]) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        if(n==1) return true;
        vector<int> power = Cpower(n);
        int p = 1;
        for(int i=2;i<31;i++){
            p = p*2;
            vector<int> parray = Cpower(p);
            if(check(parray,power)==true) return true;
        }
        return false;
    }
};
