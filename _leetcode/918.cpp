class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int all_sum = 0;
        for (int n : nums) all_sum += n;

        int max_sum = nums[0];
        int cur = 0;
        for (int n : nums) {
            if (cur < 0) cur = 0;
            cur += n;
            max_sum = max(max_sum, cur);
        }


        int min_sum = nums[0];
        cur = 0;
        for (int n : nums) {
            if (cur > 0) cur = 0;
            cur += n;
            min_sum = min(min_sum, cur);
        }

        if (all_sum == min_sum) {
            return max_sum;
        }
        return max(max_sum, all_sum - min_sum);

    }
};