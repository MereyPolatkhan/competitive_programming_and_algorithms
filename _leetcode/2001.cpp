class Solution {
public:
    long long calc(long long cnt) {
        return cnt * (cnt - 1) / 2;
    }

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> mp;

        for (auto &v: rectangles) {
            mp[(double)v[0] / v[1]]++;
        }

        long long res = 0;
        for (auto &x: mp) {
            // cout << x.first << " " << x.second << "\n";
            res += calc(x.second);
        }
        return res;
    }
};