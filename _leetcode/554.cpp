class Solution {
public:
    void calc_pf_sum(vector<int> & a) {
        for (int i = 1; i < a.size(); i++) {
            a[i] += a[i - 1];
        }
        a.pop_back();
    }
    
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;

        for (auto &v: wall) {
            calc_pf_sum(v);
            for (int &x: v) {
                mp[x]++;
            }    
        }    

        int mx = 0;
        for (auto &y: mp) {
            mx = max(mx, y.second);
        }

        return wall.size() - mx;

        return 0;
    }
    
};