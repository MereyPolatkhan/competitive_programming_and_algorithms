class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!st.count(s[i])) {
                i++;
            }
            if (!st.count(s[j])) {
                j--;
            }
            if (st.count(s[i]) and st.count(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};