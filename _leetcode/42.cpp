class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> L(n, 0);
        vector<int> R(n, 0);

        int mxL = 0;
        for (int i = 0; i < n; i++) {
            L[i] = mxL;
            mxL = max(mxL, height[i]);
        }
        
        int mxR = 0;
        for (int i = n - 1; i >= 0; i--) {
            R[i] = mxR;
            mxR = max(mxR, height[i]);
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int cur = min(L[i], R[i]) - height[i];
            cnt += cur < 0 ? 0 : cur;
        }

        return cnt;
    }
};