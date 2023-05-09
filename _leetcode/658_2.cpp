class Solution {
public:
    int bs(vector<int> a, int x) {
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == x) {
                return mid;
            }
            else if (x < a[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (abs(a[r] - x) <= abs(a[l] - x)) {
            return r;
        }
        else {
            return l;
        }
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = bs(arr, x);
        int L = index;
        int R = index;
        cout << "index=" << index << "\n";        
        int last_index = arr.size() - 1;

        while (R - L + 1 < k) {
            int dl = abs(arr[L] - x);
            int dr = abs(arr[R] - x);

            if (dl <= dr) {
                if (L > 0)
                    L--;
                else {
                    R++;
                }
            }
            else if (dl > dr) {
                if (R < last_index)
                    R++;
                else {
                    L--;
                }
            }
        }
        vector<int> res;
        cout << "L=" << L << " R=" << R << endl;
        for (int i = L; i <= R; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
