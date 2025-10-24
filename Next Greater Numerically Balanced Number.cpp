class Solution {
public:
    bool isbeautiful(vector<int> &count){
        for(int i=1;i<=7;i++){
            if(count[i]!=0 && count[i]!=i) return false;
        }
        return true;
    }
    void generate(int num,vector<int> &count,vector<int> &ans){
        if(num>0 && isbeautiful(count)){
            ans.push_back(num);
        }
        if(num>1224444) return;
        for(int i=1;i<=7;i++){
            if(count[i]<i){
                count[i]++;
                generate(num*10+i,count,ans);
                count[i]--;
            }
        }
    }
    int nextBeautifulNumber(int n) {
        vector<int> ans;
        vector<int> count(10,0);
        generate(0,count,ans);
        sort(ans.begin(),ans.end());
        for(auto ele:ans){
            if(ele>n) return ele;
        }
        return -1;
    }
};
