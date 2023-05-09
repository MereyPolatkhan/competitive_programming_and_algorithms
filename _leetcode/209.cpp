class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int res = 777777;
        int sum = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }

        if (res == 777777) {
            return 0;
        }
        return res;
    }
};