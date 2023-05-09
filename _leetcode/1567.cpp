class Solution {
public:
    int func(vector<int> & a) {
        int cnt_neg = 0;
        for (int n : a) {
            if (n < 0) {
                cnt_neg++;
            }
        }

        if (cnt_neg % 2 == 0) {
            return a.size();
        }

        unsigned long bgn = -1, end = -1;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] < 0) {
                bgn = i;
                break;
            }
        }

        for (int i = a.size() - 1; i >= 0; i--){
            if (a[i] < 0) {
                end = i;
                break;
            }
        }

        if (bgn == end) {
            return max(a.size() - 1 - bgn, bgn);
        }   
        return max(a.size() - 1 - bgn, end);
        
    }

    int getMaxLen(vector<int>& nums) {
        vector<int> cur;    
        int res = 0;
        for (int n : nums) {
            if (n == 0) {
                res = max(res, func(cur));
                cur.clear();    
            }
            else {
                cur.push_back(n);
            }
        }
        if (cur.size() > 0) {
            res = max(res, func(cur));
        }
        return res;
    }
};