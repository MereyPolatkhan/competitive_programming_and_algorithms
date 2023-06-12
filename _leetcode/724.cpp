class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> a = nums, b = nums;
        
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        for (int i = n - 2; i >= 0; i--) b[i] += b[i + 1];

        // for (int i : a) cout << i << " "; cout << "\n";
        // for (int i : b) cout << i << " "; cout << "\n";

        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) return i;
        }
        return -1;
    }
};