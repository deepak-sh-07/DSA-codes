class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxi = INT_MIN;
        int idx = -1;
        int max_wt = -1;
        for(int i=0;i<dimensions.size();i++){
            int l = dimensions[i][0]*dimensions[i][0];
            int w = dimensions[i][1]*dimensions[i][1];
            double dia = sqrt(l+w);
            if(dia>maxi){
                maxi = dia;
                max_wt = dimensions[i][0]*dimensions[i][1];
            }else if(dia==maxi){
                max_wt = max(max_wt,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return max_wt;
    }
};
