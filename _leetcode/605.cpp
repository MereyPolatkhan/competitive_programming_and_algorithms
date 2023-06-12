class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int k) {
        if (a.size() == 1 and a[0] == 0) { return true; }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) {
                if (i == 0 and i + 1 < a.size() and a[i + 1] == 0) {
                    k--;
                    a[i] = 1;
                }
                else if (i == a.size() - 1 and i - 1 >= 0 and a[i - 1] == 0) {
                    k--;
                    a[i] = 1;
                }
                else if (i - 1 >= 0 and i + 1 < a.size() and a[i - 1] == 0 and a[i + 1] == 0) {
                    a[i] = 1;
                    k--;
                }   
            }
        }
        return k <= 0;
    }
};