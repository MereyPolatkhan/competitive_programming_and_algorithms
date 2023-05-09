// ????????????????????????????

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<pair<int, int> > st;
        for (int i = 0; i < a.size(); i++) {
            if (st.size() == 0) {
                st.push({i, a[i]});
            }
            else {
                if (a[i] < st.top().second) {

                }
            }
        }
    }
};