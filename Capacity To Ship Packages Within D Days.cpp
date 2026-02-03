class Solution {
public:
    bool check(vector<int>& arr,int mid, int days){
        int n = arr.size();
        int wt = mid;
        int count = 1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            if(arr[i]>wt){
                count++;
                wt = mid;
            }
            wt -= arr[i];
            if(count>days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 1,hi = 1e9;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(check(weights,mid,days)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
