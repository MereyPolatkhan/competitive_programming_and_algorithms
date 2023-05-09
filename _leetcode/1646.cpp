class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int mx = -1;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 1; i <= n / 2; i++) {
            dp[i * 2] = dp[i];
            mx = max(mx, dp[i * 2]);
            if (i * 2 + 1 <= n) {
                dp[i * 2 + 1] = dp[i] + dp[i + 1];
                mx = max(mx, dp[i * 2 + 1]);
            }
        }

        return mx;
    }
};