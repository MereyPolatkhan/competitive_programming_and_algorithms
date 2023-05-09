class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int i = 0;
        int j = 0;

        while (j < chars.size()) {
            if (chars[i] == chars[j]) {
                j++;
            }
            else {
                s += chars[i];
                if (j - i > 1) s += to_string(j - i);
                i = j;
            }
        }

        s += chars[i];
        if (j - i > 1) s += to_string(j - i);
        
        chars.clear();
        for (int i = 0; i < s.size(); i++) {
            chars.push_back(s[i]);
        }

        return chars.size();
    }
};