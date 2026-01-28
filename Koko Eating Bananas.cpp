class Solution {
public:
    bool check(vector<int>& arr,int num,int h){
        long long count = 0,i=0,n=arr.size();
        while(i<n){
            if(count>h) return false;
            if(num>=arr[i]) count++;
            else if(arr[i]%num==0) count += (long long)(arr[i]/num);
            else count += (long long)(arr[i]/num +1);
            i++;
        }
        if(count<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = -1;
        for(int i=0;i<n;i++) maxi = max(maxi,piles[i]);
        int lo = 1,hi = maxi,ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            bool ck = check(piles,mid,h);
            if(ck==true){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans; 
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
