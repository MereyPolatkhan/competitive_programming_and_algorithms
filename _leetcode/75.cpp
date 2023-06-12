class Solution {
public:
    void sortColors_(vector<int>& a) {
        int l = 0;
        int r = a.size() - 1;

        int i = 0;
        while (i <= r) {
            if (a[i] == 0) {
                swap(a[i], a[l]);
                l++;
            }
            else if (a[i] == 2) {
                swap(a[i], a[r]);
                r--;
                i--;
            }
            i++;
        }
    }

    void sortColors(vector<int>& a) {
        vector<int> c(3, 0);
        for (int &x: a) {
            c[x]++;
        }

        int k = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < c[i]; j++) {
                a[k++] = i;
            }
        }
        
    }
};