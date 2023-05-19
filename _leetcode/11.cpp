class Solution {
public:
    int calc(int i, int j, vector<int>& a) {
        if (i < j) {
            return (j - i) * min(a[i], a[j]);
        }
        return 0;
    }
    int maxArea(vector<int>& a) {
        int n = a.size();
        
        int res = -1e9;

        int i = 0;
        int j = n - 1;


        while(i < j) {
            res = max(res, calc(i, j, a));
            if (a[i] < a[j]) i++;
            else j--;
        }

        return res;
    }
};