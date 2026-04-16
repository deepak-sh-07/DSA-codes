class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> res(queries.size());
        for(int i=0;i<queries.size();i++){
            int idx = queries[i];
            int num = nums[idx];
            vector<int>& helper = mp[num];
            int ans = INT_MAX;
            if(helper.size()==1){
                res[i] = -1;
                continue;
            }
            // int lo = 0,hi = helper.size()-1;
            // int pos = -1;
            // while(lo<=hi){
            //     if(helper.size()==1) break;
            //     int mid = lo+(hi-lo)/2;
            //     if(helper[mid]==idx){
            //         pos = mid;
            //         break;
            //     }else if(helper[mid]<idx) lo = mid+1;
            //     else hi = mid-1;
            // }
            int pos = lower_bound(helper.begin(), helper.end(), queries[i]) - helper.begin();
            int left = helper[(pos-1+helper.size())%helper.size()];
            int right = helper[(pos+1)%helper.size()];

            int d1 = abs(idx - left);
            int d2 = abs(idx - right);

            res[i] = min({d1, d2, n-d1, n-d2});
        }
        return res;
    }
};
