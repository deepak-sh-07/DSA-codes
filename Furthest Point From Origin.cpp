class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int dash = 0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') left++;
            else if(moves[i]=='R') right++;
            else dash++;
        }
        if(left>right) return left-right+dash;
        else if(right>left) return right-left+dash;
        return dash;
    }
};
