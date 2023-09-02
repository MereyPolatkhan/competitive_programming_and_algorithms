bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({cost[i], time[i]});
        }
        
        sort(a.begin(), a.end(), cmp);
        
        for (auto i: a) {
            cout << i.first << " " << i.second << "\n";
        } cout << "\n\n";
            
        
        int i = 0;
        int j = n - 1;
        int res = 0;
        while (i <= j) {
            if (i == j) {
                res += a[i].first;
                return res;
            }
            res += a[i].first;
            int time_paid = a[i].second;
            i++;
            for (int k = 1; k <= time_paid; k++) {
                j--;    
            }
        }
        return res;
        
    }
};