class Solution {
public:
    int bs_left(vector<int>& a, int x) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << "bsl: " << l << " " << r << "\n";
        return l;
    }
    
    int bs_right(vector<int>& a, int x) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << "bsr: " << l << " " << r << "\n";
        return r;
    }

    bool bs(vector<int>& a, int x) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == x) {
                return true;
            }
            else if (a[mid] < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (bs(nums, target) == false) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(bs_left(nums, target));
        res.push_back(bs_right(nums, target));

        return res;
    }
};