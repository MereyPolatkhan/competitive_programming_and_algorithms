class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        if (n == 2) return max(nums[0], nums[1]);
        
        vector<int> a;
        vector<int> b;
        
        for (int i = 0; i < n - 1; i++) a.push_back(nums[i]);
        for (int i = 1; i < n; i++) b.push_back(nums[i]);
 
        return max(robbing(a), robbing(b));
    }
    
    int robbing(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        nums[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        return max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};