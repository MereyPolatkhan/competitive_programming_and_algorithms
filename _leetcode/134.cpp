class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            cur += (gas[i] - cost[i]);
            if (cur < 0) {
                cur = 0;
                res = i + 1;
            }
        }
        if (sum < 0) return -1;
        return res;   
    }
};