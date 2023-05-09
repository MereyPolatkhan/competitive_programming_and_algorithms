class Solution {
public:
    bool isUppercase(char c) {
        if (int(c) >= 'A' && int(c) <= 'Z') {
            return true;
        }
        return false;
    }

    char lower(char c) {
        return (char)((int)c + 32);
    }

    bool isChar(char c) {
        if ((int(c) >= 'a' && int(c) <= 'z') || 
            (int(c) >= 'A' && int(c) <= 'Z') ||
            (int(c) >= '0' && int(c) <= '9')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (isUppercase(s[i])) {
                s[i] = lower(s[i]);
            }
            if (!isChar(s[i])) {
                s[i] = ' ';
            }
        }
        cout << s << "\n";
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << s << "\n";
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
};
