class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int x: coins) {
                if (i - x >= 0) 
                    dp[i] = min(dp[i], dp[i - x]+1);
            }
        }

        // for (int i = 0; i <= amount; i++) {
        //     cout << i << ": " << dp[i] << "\n";
        // }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};