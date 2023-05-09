#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[i] == s[j] ){
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {

    string s;
    cin >> s;

    int n = s.size();

    vector<int> p = kmp(s);

    cout << n - p[p.size() - 1];

    return 0;
}