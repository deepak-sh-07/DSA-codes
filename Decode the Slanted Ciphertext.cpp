class Solution {
public:
    string decodeCiphertext(string s, int rows) { // optimal solution
        int n = s.length();
        int m = n/rows;
        int idx = 0;
        int i=0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=' ') count++;
        }
        string ans = "";
        while(count>0){
            ans += s[i];
            if(s[i]!=' ') count--;
            i = i+m+1;
            if(i>=n){
                idx++;
                i = idx;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     string decodeCiphertext(string s, int rows) {
//         int n = rows;
//         int m = s.length()/rows;
//         vector<vector<char>> arr(n,vector<char>(m));
//         int k = 0;
//         int count = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(s[k]==' ') arr[i][j] = ' ';
//                 else{
//                     arr[i][j] = s[k];
//                     count++;
//                 }
//                 k++;
//             }
//         }
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<m;j++){
//         //         cout<<arr[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         int i=0,j=0;
//         int x = 0;
//         int c= 0;
//         string ans = "";
//         while(c<count){
//             ans += arr[i][j];
//             if(arr[i][j]!=' ') c++;
//             i++;
//             j++;
//             if(i==rows || j==m){
//                 x++;
//                 i = 0;
//                 j = x;
//             }
//         }
//         return ans;
//     }
// };
