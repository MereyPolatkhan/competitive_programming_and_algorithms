bool cmp(string a, string b) {
    return a + b < b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for (int &x: nums) {
            a.push_back(to_string(x));
        }

        sort(a.rbegin(), a.rend(), cmp);

        string s = "";
        for (string &x: a) {
            if (!(s.empty() and x == "0")) s += x;
        }
        return s.empty() ? "0" : s;
    }
};