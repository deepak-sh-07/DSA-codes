class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        for (int i = 0; i < num.length(); i++) {
            while (!stack.empty() && k > 0 && stack.top() > num[i]) {
                stack.pop();
                k--;
            }
            stack.push(num[i]);
        }
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        string res = "";
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        for (int j = 0; j < res.length(); j++) {
            if (res[i] != '0')
                break;
            i++;
        }
        res = res.substr(i);
        if (res.length() == 0)
            return {"0"};
        return res;
    }
};
