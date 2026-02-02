class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        set<P> kele;
        set<P> remaining;
        ll sum = 0;
        int i=1;
        int n = nums.size();
            while(i-dist<1){
                kele.insert({nums[i],i});
                sum += nums[i];
                if(kele.size()>k-1){
                    P ele = *kele.rbegin();
                    sum -= ele.first;
                    remaining.insert(ele);
                    kele.erase(ele);
                }
                i++;
            }
            ll ans = LONG_MAX;
            while(i<n){
                kele.insert({nums[i],i});
                sum += nums[i];
                if(kele.size()>k-1){
                    P ele = *kele.rbegin();
                    sum -= ele.first;
                    remaining.insert(ele);
                    kele.erase(ele);
                }
                ans = min(sum,ans);
                //remove ele
                P remove = {nums[i-dist],i-dist};
                if(kele.count(remove)){
                    kele.erase(remove);
                    sum -= remove.first;

                    if(!remaining.empty()){
                        P add = *remaining.begin();
                        kele.insert(add);
                        sum += add.first;
                        remaining.erase(add);
                    }
                }else remaining.erase(remove);
                i++;
            }
        return nums[0]+ans;
    }
};
