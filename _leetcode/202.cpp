class Solution {
public:
    int calc(int n) {
        int sum = 0;
        while (n > 0) {
            int num = n % 10;
            n /= 10;
            sum += (num * num);
        } 
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while (n != 1 and st.count(n) != 1) {
            st.insert(n);
            n = calc(n);
        }      

        return 1 == n;
    }
};