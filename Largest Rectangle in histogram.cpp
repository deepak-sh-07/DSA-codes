class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
  int nsi[n];
  nsi[n-1] = n;
  st.push(n-1);
  for(int i = n-2;i>=0;i--){
    while(st.size()!=0 && arr[st.top()]>=arr[i]) st.pop();
    if(st.size()==0) nsi[i]=n;
    else nsi[i] = st.top();
    st.push(i);
  }

 int psi[n];
 stack<int>gt;
 gt.push(0);
 psi[0] = -1;
 for(int i=1;i<n;i++){
    while(gt.size()!=0 && arr[gt.top()]>=arr[i]) gt.pop();
    if(gt.size()==0) psi[i]=-1;
    else psi[i] = gt.top();
    gt.push(i);
 }
 int ans[n];
 int maxlen = INT_MIN;
 for(int i=0;i<n;i++){
    ans[i] = arr[i] * (nsi[i]-psi[i]-1);
    maxlen = max(maxlen,ans[i]);
 }
 return maxlen;
    }
};
