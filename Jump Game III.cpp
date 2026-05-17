class Solution {
public:
    vector<int> visited;
    bool f(int start,vector<int>& arr){
        if(start>=arr.size() || start<0 || visited[start]==true) return false;
        if(arr[start]==0) return true;
        visited[start] = true;
        bool left = f(start-arr[start],arr);
        bool right = f(start+arr[start],arr);
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        visited.resize(n,false);
        return f(start,arr);
    }
};
