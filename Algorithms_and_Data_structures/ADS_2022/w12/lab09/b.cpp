#include <iostream>
#include <vector>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    string t; cin >> t;
    int k; cin >> k;
    string s; cin >> s;

    vector<int> p = kmp(t + "$" + s);

    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == t.size()) {
            cnt++;
        }
    }

    if (cnt >= k) cout << "YES";
    else cout << "NO";

    return 0;
}