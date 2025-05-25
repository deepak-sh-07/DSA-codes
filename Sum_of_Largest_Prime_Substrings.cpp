class Solution {
public:
    bool isPrime(long long int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (long long int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n = s.length();
        unordered_map<long long int, long long int> mp;
        priority_queue<long long int> pq;
        for (int i = 0; i < n; i++) {
            string x = "";
            for (int j = i; j < n; j++) {
                x = x + s[j];
                long long int num = stoll(x);
                if (isPrime(num) == false)
                    continue;
                if (mp.find(num) == mp.end()) {
                    mp[num]++;
                    pq.push(num);
                }
            }
        }
        int k = 0;
        long long int sum = 0;
        while (pq.size() > 0 && k < 3) {
            sum = sum + pq.top();
            pq.pop();
            k++;
        }
        return sum;
    }
};
