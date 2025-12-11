class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& building) {
        vector<int> maxR(n+1,0);
        vector<int> maxC(n+1,0);
        vector<int> minR(n+1,n+1);
        vector<int> minC(n+1,n+1);
        for(int i=0;i<building.size();i++){
            int x = building[i][0], y = building[i][1];
            maxR[x] = max(maxR[x],y);
            minR[x] = min(minR[x],y);
            maxC[y] = max(maxC[y],x);
            minC[y] = min(minC[y],x);
        }
       int ans = 0;
        for(int i=0;i<building.size();i++){
            int x = building[i][0], y = building[i][1];
            if(y<maxR[x] && y>minR[x] && x<maxC[y] && x>minC[y]) ans++;
        }
        return ans;
    }
};
