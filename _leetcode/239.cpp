class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        int lmx = nums[0];

        for (int i = 0; i < k; i++) {
            dq.push_back(nums[i]);
            lmx = max(lmx, nums[i]);
        }

        res.push_back(lmx);

        for (int i = k; i < nums.size; i++) {
            lmx = max(lmx, nums[i]);
            while(dq.front() != lmx && dq.size() > 0) {
                dq.pop_front();
            }
            dq.push_back(nums[i]);
            res.push_back(dq.front());
        }

        
        return res;
    }
};