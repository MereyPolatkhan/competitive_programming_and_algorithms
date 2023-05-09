class Solution {
public:
    priority_queue <int> pq;
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++){ // n
            pq.push(nums[i]);
        }

        while (k > 1){ // k log n 
            pq.pop();
            k--;
        }
        return pq.top();
    } // n + k log n
};