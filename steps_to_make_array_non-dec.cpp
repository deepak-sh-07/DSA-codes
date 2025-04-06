class Solution {
    public:
        int totalSteps(vector<int>& nums) {
            stack<pair<int, int>> stack;
            stack.push({nums[0], 0});
            int steps = 0;
            for (int i = 1; i < nums.size(); i++) {
                int temp = 0;
                while (!stack.empty() && stack.top().first <= nums[i]) {
                    temp = max(temp, stack.top().second);
                    stack.pop();
                }
                if (!stack.empty()) {
                    temp += 1;
                } else {
                    temp = 0;
                }
                steps = max(steps, temp);
                stack.push({nums[i], temp});
            }
            return steps;
        }
    };//2289