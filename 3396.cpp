class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int,int> mp;
            int n = nums.size();
            int count = 0;
            for(int i=0;i<n;i++){
                if(mp.find(nums[i])!=mp.end()) count++;
                mp[nums[i]]++;
            }
            if(count==0) return 0;
            int total = 0;
            int i=0;
            cout<<count;
            while(count>0 && i<n){
                for(int j=i;j<3+i && j<n;j++){
                    if(mp[nums[j]]>1){
                        mp[nums[j]]--;
                        count--;
                    }else{
                        mp.erase(nums[j]);
                    }
                }
                i = i+3;
                total++;
            }
            return total;
        }
    };