class Solution {
    public:
        string originalDigits(string s) {
           unordered_map<char,int> mp;
           int nums[10];
           int n = s.length();
           for(int i=0;i<n;i++){
            mp[s[i]]++;
           } 
           nums[0] = mp['z'];
           nums[2] = mp['w'];
           nums[4] = mp['u'];
           nums[5] = mp['f']-nums[4];
           nums[6] = mp['x'];
           nums[8] = mp['g'];
           nums[1] = mp['o']-nums[0]-nums[2]-nums[4];
           nums[3] = mp['h']-nums[8];
           nums[7] = mp['s']-nums[6];
           nums[9] = mp['i']-nums[6]-nums[8]-nums[5];
           string res= "";
           for(int i=0;i<10;i++){
            if(nums[i]!=0){
                res += string(nums[i],'0'+i);
            }
           }
           return res;
    
        }
    };