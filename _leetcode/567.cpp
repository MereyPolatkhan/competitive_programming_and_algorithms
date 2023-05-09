class Solution { // O(L1 + (L2-L1)) = O(n)
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);


        for (int i = 0; i < s1.size(); i++) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] == b[i]) cnt++;
        }

        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (cnt == 26) return true;
            int l = s2[i] - 'a';
            int r = s2[i + s1.size()] - 'a';


            b[r]++;
            if (a[r] == b[r]) cnt++;
            else if (a[r] + 1 == b[r]) cnt--;

            b[l]--;
            if (a[l] == b[l]) cnt++;
            else if (a[l] - 1 == b[l]) cnt--;

        }
        return (cnt == 26);
    } 
};



class Solution { // O(L1 + 26(L2-L1)) = O(26n)
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (check(a, b)) return true;
            b[s2[i + s1.size()] - 'a']++;
            b[s2[i] - 'a']--;
        }

        return check(a, b);
    } 

    bool check(vector<int>& a, vector<int>& b) { // O(26)
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};