class Solution {
    public:
        int numRabbits(vector<int>& arr) {
            int n = arr.size();
            int ans = 0;
            sort(arr.begin(),arr.end());
            ans = ans + arr[0]+1;
            int i=1;
            int count = 1; 
            while(i<n){
                if(arr[i]==0) ans = ans+1; 
                else if(arr[i]==arr[i-1]){
                   count++;
                   if(count>arr[i]+1){
                    ans = ans + arr[i]+1;
                    count=1;
                   }
                }else{
                    ans = ans + arr[i]+1;
                    count=1;
                   }
                i++;
            }
            return ans;
        }
    };