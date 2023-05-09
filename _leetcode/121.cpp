class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int l = 0;
        int r = 1;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                mx = max(mx, profit); 
            }
            else {
                l = r;
            }
            r++;
        }

        return mx;
    }
};