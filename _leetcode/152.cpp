class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        int cur_min = 1;
        int cur_max = 1;

        for (int n : nums) {
            if (n == 0) {
                cur_min = 1;
                cur_max = 1;
            }

            int prod_cur_min = cur_min * n;
            int prod_cur_max = cur_max * n;

            cur_min = min({n, prod_cur_min, prod_cur_max});
            cur_max = max({n, prod_cur_min, prod_cur_max});
            // cout << cur_min << " " << cur_max << "\n";
            res = max({cur_max, res, n, cur_min});
        }

        return res;
    }
};