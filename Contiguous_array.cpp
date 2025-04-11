class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            vector<int>demo(nums.begin(),nums.end());
            for(int i=0;i<demo.size();++i){
                if(demo[i]==0) demo[i]=-1;
            }
            unordered_map<int,int>mp; //stores sum
             mp[0]=-1; //incase contiguous array starts from 0 idx
            int sum=0,ans=0;
            for(int i=0;i<demo.size();i++){
                sum+=demo[i];
                if(mp.count(sum)){ //if sum present the update
                    ans=max(ans,i-mp[sum]);
                }
                if(!mp.count(sum))mp[sum]=i; //if sum isnt present then enter the sum
            }
            return ans;
        }
    };