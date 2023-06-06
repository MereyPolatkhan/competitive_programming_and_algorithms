class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int even_ind = 0;
        int odd_ind = 1;
        while (even_ind < a.size()) {
            if (a[even_ind] % 2 == 1) {
                while (a[odd_ind] % 2 == 1) {
                    odd_ind += 2;
                }
                swap(a[even_ind], a[odd_ind]);
            }
            even_ind += 2;
        }
        return a;
    }
};