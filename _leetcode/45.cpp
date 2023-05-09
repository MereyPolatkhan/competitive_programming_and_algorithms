// O(N) time O(1) memory

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int flag = n - 1;
        int last = flag;
        int k = 0;
        
        while (flag != 0) {
            int i = flag - 1;
            
            while (i >= 0) {
                if (nums[i] + i >= last) {
                    flag = i;
                }
                i--;
            }
            last = flag;
        
            k++;
        
        }
        return k;
    }
};