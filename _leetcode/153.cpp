class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        if (nums.size() == 1 || nums[l] < nums[r]) {
            return nums[0];
        }


        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid - 1 >= 0 and nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (mid + 1 < nums.size() and nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[l] > nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return 7e7;
    }
};