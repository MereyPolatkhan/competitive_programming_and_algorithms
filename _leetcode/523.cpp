class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        unordered_map<int, int> m;
        m[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            int remainder = nums[i] % k;
            if (m.count(remainder) == 0) {
                m[remainder] = i;
            }
            else if (m[remainder] + 2 <= i) {
                return true;
            }
            
        }

        return false;
    }
};