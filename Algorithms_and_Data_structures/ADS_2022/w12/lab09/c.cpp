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

    string s, t;
    cin >> s >> t;

    string q = t + "$" + s + s;

    vector<int> p = kmp(q);

    for (int i = t.size(); i < p.size(); i++) {
        if (p[i] == t.size()) {
            cout << t.size() - (i - 2 * t.size());
            return 0;
        }
    }

    cout << -1;

    return 0;
}