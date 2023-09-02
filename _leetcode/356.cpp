// author: @assabiyah


class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        set<pair<int, int>> st;
        
        for (vector<int> & a: points) {
            st.insert({a[0], a[1]});
        }

        int min_y = INT_MAX, max_y = INT_MIN;

        for (const pair<int, int> & p: st) {
            min_y = min(min_y, p.first);
            max_y = max(max_y, p.first);
        } 

        double mid = ((double)min_y + (double)max_y) / 2;

        for (const pair<int, int> & p: st) {
            if (st.count({mid + (mid - p.first), p.second}) == 0) {
                return false;
            }
        }
        return true;
    }
};



class Solution2 {
public:
    double mid_odd(vector<int> & a) {
        int mid = a.size() / 2;
        int i = mid - 1, j = mid + 1;
        while (i >= 0 and j < a.size()) {
            if (a[mid] - a[i] != a[j] - a[mid]) {
                return -1e9;
            }
            else {
                i--;
                j++;
            }
        }
        return (double)a[mid];
    }

    double mid_even(vector<int> & a) {
        int j = a.size() / 2;
        int i = j - 1;
        double mid_val = ((double)a[i] + (double)a[j]) / 2;
        
        while (i >= 0 and j < a.size()) {
            if (mid_val - (double)a[i] != (double)a[j] - mid_val) {
                return -1e9;
            }
            else {
                i--;
                j++;
            }
        }
        return mid_val;
    }   

    double get_mid(vector<int> & a){ 
        if (a.size() == 1) {
            return a[0];
        }
        else if (a.size() % 2 == 1) {
            return mid_odd(a);
        }
        else {
            return mid_even(a);
        }
    }

    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, set<int>> temp;

        for (vector<int> & a: points) {
            temp[a[1]].insert(a[0]);
        }

        for (auto &u: temp) {
            for (const int &x: u.second) {
                mp[u.first].push_back(x);
            }
        }

        vector<double> mids;

        for (auto & yx: mp) {
            double mid = get_mid(yx.second);
            if (mid == -1e9) {
                return false;
            }
            mids.push_back(mid);
        }
        return *min_element(mids.begin(), mids.end()) == *max_element(mids.begin(), mids.end());

    }
};