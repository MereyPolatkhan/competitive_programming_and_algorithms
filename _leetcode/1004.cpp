class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0;
        int res = 0;
        int cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            }
            if (cnt > k) {
                if (nums[j] == 0) {
                    cnt--;
                }
                j++;
            }
            // res = max(res, i - j + 1);
        }
        return nums.size() - j;
    }
};