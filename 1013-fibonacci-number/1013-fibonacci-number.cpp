class Solution {
public:
    int fib(int n) {
        // base case
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, -1);

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};