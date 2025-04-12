
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int n = intervals.size();
            int j = 0;
            vector<vector<int>> ans;
            bool flag = false;
            for(int i=0;i<n;i++){
                if(intervals[i][0]>newInterval[0] && flag==false){
                    ans.push_back({newInterval[0],newInterval[1]});
                    flag = true;
    
                }
                    ans.push_back(intervals[i]);
                
            }
            //merge interval
            if(ans.size()==n){
               ans.push_back({newInterval[0],newInterval[1]}); 
            }
            n = n+1;
            for(int i=0;i<n;i++){
                 cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
            }
            for(int i=0;i<n-1;i++){
                 if(ans[i][1]>=ans[i+1][0] ){
                    ans[i+1][0] = ans[i][0];
                    ans[i+1][1] = max(ans[i+1][1],ans[i][1]);
                    ans[i][0] = -1;
                    ans[i][1] = -1; 
                 }
            }
            for(int i=0;i<n;i++){
                 cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
            }
            vector<vector<int>> main;
            for(int i=0;i<n;i++){
                if(ans[i][0]==-1) continue;
                main.push_back(ans[i]);
            }
            return main;
        }
    };