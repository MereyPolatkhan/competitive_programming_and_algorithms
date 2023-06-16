class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;

        for (char &c: s) {
            if (c == '[') {
                cnt++;
            }
            else {
                cnt = max(0, cnt - 1);
            }
        }
        return (cnt + 1) / 2;
    }
};