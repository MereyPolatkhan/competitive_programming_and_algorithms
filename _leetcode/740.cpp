
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> dp(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[nums[i]] += nums[i];
        }      

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);    
        }

        // for (auto i: dp) cout << i << " "; cout << endl;
        return max(dp[n - 1], dp[n - 2]);
    }
};
