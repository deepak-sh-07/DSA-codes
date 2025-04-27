class Solution {
    public:
        string find(const vector<string>& words) {
    
        return *min_element(words.begin(), words.end());
    }
        string findCommonResponse(vector<vector<string>>& arr) {
            int n = arr.size();
            int k=0;
            vector<string> ans;
            for (int i = 0; i < n; i++) {
                unordered_map<string, int> mp;
                int m = arr[i].size();
                for(int j=0;j<m;j++){
                    mp[arr[i][j]]++;
                }
                for(auto ele:mp){
                    ans.push_back(ele.first);
                    
                }
            }
            n = ans.size();
            int maxi = INT_MIN;
            unordered_map<string, int> mp;
            for(int i=0;i<n;i++){
                mp[ans[i]]++;
                maxi = max(maxi,mp[ans[i]]);
            }
            vector<string> helper;
            for(auto ele:mp){
                if(ele.second==maxi) helper.push_back(ele.first);
            }
            if(helper.size()==1) return helper[0];
            return find(helper);
        }
    };