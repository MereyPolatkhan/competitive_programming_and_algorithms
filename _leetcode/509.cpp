class Solution {
public:
    int fib(int n) {
        int dp[n + 2];

        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
// Memory Usage: 5.8 MB, less than 78.79% of C++ online submissions for Fibonacci Number.
