class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int>& candidates,int t,int idx,vector<int>& subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        if(idx==candidates.size()) return;
        if(candidates[idx]<=t){
            subset.push_back(candidates[idx]);
            f(candidates,t-candidates[idx],idx,subset);
            subset.pop_back();
        }
        int j = idx+1;
        // while(j<candidates.size() && candidates[j]==candidates[j-1]) j++;
        f(candidates,t,j,subset);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
       vector<int> subset;
       result.clear();
       f(candidates,target,0,subset);
       return result;
    }
};
