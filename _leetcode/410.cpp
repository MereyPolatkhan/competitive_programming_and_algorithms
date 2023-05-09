class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = nums[0];
        int r = 0;

        for (auto x: nums) {
            l = max(l, x);
            r += x;
        }  
        
        int res;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            int cnt = 1;

            for (auto n: nums) {
                if (sum + n > mid) {
                    sum = n;
                    cnt++;
                }    
                else sum += n;
            }
            // cout << mid << "\n";

            if (cnt <= k) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return res;
    }
};