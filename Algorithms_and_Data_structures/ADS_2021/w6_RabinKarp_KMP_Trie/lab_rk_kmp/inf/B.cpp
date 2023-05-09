// Accepted 
#include <bits/stdc++.h> 

using namespace std;

vector<int> pf(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j = j + 1;
        }
        p[i] = j;
    }
    return p;
}

int main() {

    string s;
    cin >> s;
    
    vector<int> p = pf(s);

    int last = p[p.size() - 1];
    string t = s.substr(0, p.size() - last);

    int ss = s.size();
    int ts = t.size();
    
    if (ss % ts == 0)
        cout << ss / ts;
    else 
        cout << 1;
    return 0;
}