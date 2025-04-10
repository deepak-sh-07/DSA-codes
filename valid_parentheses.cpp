class Solution {
    public:
        bool isValid(string s) {
            if(s.length()%2==1) return false;
          stack<char> st;
          for(int i=0;i<s.length();i++){
            if(s[i]=='(') {st.push(s[i]);
           }
            if(s[i]=='[') {st.push(s[i]);
           } 
           if(s[i]=='{') {st.push(s[i]);
           }
            else if(s[i]==')'){
                if(st.size()==0) return false;
                if(st.top()=='(') st.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(st.size()==0) return false;
                if(st.top()=='[') st.pop();
                else return false;
            }
           else if(s[i]=='}'){
            if(st.size()==0) return false;
                if(st.top()=='{') st.pop();
                else return false;
            }
            
          } 
          if(st.size()==0) return true;
          return false; 
        }
    };