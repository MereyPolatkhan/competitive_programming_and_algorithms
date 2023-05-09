class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        
        for (auto x: piles) {
            r = max(r, x);
        }

        long long res;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long hours = 0;
            for (auto x: piles) {
                hours += ceil(x * (1.0) / mid);
            }
            // cout << "mid=" << mid << " hours=" << hours  << endl;
            if (hours <= h) {
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