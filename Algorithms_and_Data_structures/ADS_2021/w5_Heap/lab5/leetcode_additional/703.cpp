// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int global_k;
    KthLargest(int k, vector<int>& nums) {
        global_k = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (k < pq.size()) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if (global_k < pq.size())
            pq.pop();
        
        return pq.top();
    }
};
