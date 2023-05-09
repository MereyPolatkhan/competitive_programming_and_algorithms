class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = nums[0];
        for (auto x: nums) r = max(r, x);

        int res; 
        int k;
        while (l <= r) {
            int mid = (l + r) / 2;
            k = 0;
            for (auto x: nums) {
                k += (x - 1) / mid;
            }
            // cout << k << "\n";
            
            if (k <= maxOperations) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }   
        cout << k;

        return res;
    }   
};