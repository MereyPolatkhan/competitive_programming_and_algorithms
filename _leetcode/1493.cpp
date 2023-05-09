class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int cur = 0;
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur++;
            }
            else {
                if (index == -1) {
                    cur++;
                }
                else {
                    cur = i - index;
                }
                index = i;
            }
            res = max(res, cur);
        }
        return res - 1;
    }
};