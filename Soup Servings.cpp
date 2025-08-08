class Solution {
public:
    vector<vector<double>> dp;
    vector<vector<int>> op = {{100,0},{75,25},{50,50},{25,75}};
    double prob(int a ,int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0;
        if(dp[a][b]!=-1) return dp[a][b];
        double ans = 0.0;
        for(int i=0;i<4;i++){
            int newA = a-op[i][0];
            int newB = b-op[i][1];
            ans += prob(newA,newB);
        }
        return dp[a][b] = 0.25*ans;
    }
    double soupServings(int n) {
        
        if(n>=4800) return 1;
        dp.clear();
        dp.resize(n+1,vector<double>(n+1,-1));
        return prob(n,n);
    }
};
