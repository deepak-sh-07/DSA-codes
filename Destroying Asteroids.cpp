class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
       sort(arr.begin(),arr.end());
       long long ans = mass;
       int n = arr.size();
       for(int i=0;i<n;i++){
        if(ans<arr[i]) return false;
        ans += arr[i];
       } 
       return true;
    }
};
