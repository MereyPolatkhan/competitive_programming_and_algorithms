class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = nums[0];
        
        for (auto x: nums) {         
            cur_sum = max(cur_sum + x, x);
            max_sum = max(max_sum, cur_sum);
        }
        
        return max_sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;

        int cur_sum = 0;
        
        for (auto x: nums) {
            cur_sum += x;
            dp.push_back(cur_sum);
           
            if (cur_sum < 0) {
                cur_sum = 0;
            }
        }
        
        int max_sum = dp[0];
        
        for (auto x: dp) max_sum = max(max_sum, x);
        
        return max_sum;
    }
};