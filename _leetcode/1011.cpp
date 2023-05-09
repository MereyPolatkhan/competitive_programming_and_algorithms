class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0];
        int r = 0;
        int res;
        for (auto x: weights) {
            l = max(l, x);
            r += x;
        }

        while (l <= r) {
            int mid = (l + r) / 2;

            int mass = 0;
            int day = 1;
            for (auto x: weights) {
                mass += x;
                if (mass > mid) {
                    mass = x;
                    day++;
                }
            }

            if (day <= days) {
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