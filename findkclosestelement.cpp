class Solution {
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();
            int lo = 0,hi = n-1;
            bool flag = false;
            vector<int> ans;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(arr[mid]==x){
                    ans.push_back(arr[mid]);
                    k--;
                    lo = mid-1,hi = mid+1;
                    while(k>0){
                        if(lo<0) ans.push_back(arr[hi++]);
                        else if(hi>n-1) ans.push_back(arr[lo--]);
                        else{
                            if(x-arr[lo]<=arr[hi]-x) ans.push_back(arr[lo--]);
                            else ans.push_back(arr[hi++]);
                        }
                        k--;
                    }
                    sort(ans.begin(),ans.end());
                   return ans;
                }else if(arr[mid]<x) lo = mid+1;
                 else hi = mid-1;
            }
           
            int num = lo;
            lo = hi;
            hi = num;
            
            while(k>0){
                        if(lo<0) ans.push_back(arr[hi++]);
                        else if(hi>n-1) ans.push_back(arr[lo--]);
                        else{
                            cout<<x-arr[lo]<<arr[hi]-x;
                            if(x-arr[lo]<=arr[hi]-x) ans.push_back(arr[lo--]);
                            else ans.push_back(arr[hi++]);
                        }
                        k--;
                    }
                    sort(ans.begin(),ans.end());
                   return ans;
        }
    };//leetcode 658