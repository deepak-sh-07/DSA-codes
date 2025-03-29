class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            n = n*n;
            int x = maxWeight/w;
            if(x<n) return x;
            return n;
    
        }
    };