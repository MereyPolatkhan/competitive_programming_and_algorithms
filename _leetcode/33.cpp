class Solution {
public:
    int bs1(vector<int> & a) {
        int l = 0;
        int r = a.size() - 1;
        if (a.size() == 1 or a[l] < a[r]) return a[0];

        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid - 1 >= 0 and a[mid - 1] > a[mid]) return mid;
            if (mid + 1 < a.size() and a[mid] > a[mid + 1]) return mid + 1;
            if (a[l] < a[mid]) l = mid + 1;
            else r = mid - 1;
        }

        return 1e9;
    }

    int bs2(vector<int> & a, int l, int r, int x) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == x) return mid;
            else if (a[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int inflection = bs1(nums);

        int fst = bs2(nums, 0, inflection - 1, target);
        int scd = bs2(nums, inflection, nums.size() - 1, target);

        if (fst == -1) {
            return scd == -1 ? -1 : scd;
        }
        else {
            return fst;
        }
    }
};