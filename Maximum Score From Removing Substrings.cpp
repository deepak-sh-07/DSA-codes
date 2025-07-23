class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int max = 0;
        if (x > y) {
            for (int i = 0; i < s.length(); i++) {
                if (st.size() == 0)
                    st.push(s[i]);
                else if (s[i] == 'b' && st.top() == 'a') {
                    max += x;
                    st.pop();
                } else
                    st.push(s[i]);
            }
            stack<char> dum;
            while (st.size()) {
                if (dum.size() == 0) {
                    dum.push(st.top());
                } else if (st.top() == 'b') {

                    if (dum.top() == 'a') {
                        max += y;
                        dum.pop();
                    } else
                        dum.push(st.top());
                } else
                    dum.push(st.top());
                st.pop();
            }
        } else {
            for (int i = 0; i < s.length(); i++) {
                if (st.size() == 0)
                    st.push(s[i]);
                else if (s[i] == 'a' && st.top() == 'b') {
                    max += y;
                    st.pop();
                } else
                    st.push(s[i]);
            }
            stack<char> dum;
            while (st.size()) {
                if (dum.size() == 0) {
                    dum.push(st.top());
                } else if (st.top() == 'a') {
                    if (dum.top() == 'b') {
                        max += x;
                        dum.pop();
                    } else
                        dum.push(st.top());
                } else
                    dum.push(st.top());
                st.pop();
            }
        }
        return max;
    }
};
