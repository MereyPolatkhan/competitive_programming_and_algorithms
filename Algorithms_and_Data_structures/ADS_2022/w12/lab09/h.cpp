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
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;


    vector<int> p = kmp(s);

    int res = 0;

    for (int i = 2; i < p.size(); i += 2) {
        if (p[i - 1] != 0) {
            int j = i - p[i - 1];
            if ((i / j) % 2 == 0 && i % j == 0) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}