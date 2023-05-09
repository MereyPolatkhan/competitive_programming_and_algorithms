class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> res;
        int l = 0;
        int r = a.size() - 1;

        while (true) {
            if (a[l] + a[r] == target) {
                res.push_back(l + 1);
                res.push_back(r + 1);
                break;
            }
            else if (a[l] + a[r] < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return res;
    }
};