// Accepted
#include <bits/stdc++.h> 

using namespace std;

vector<int> p_f(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[i] == s[j]) 
            j = j + 1;
        p[i] = j;
    }
    return p;
}

int main() {

    while(true) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }

        map <string, int> v;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v[s] = 0;
        }

        string main; 
        cin >> main;
        int mx = -1;
        for (auto j: v) {
            string sub = j.first;
            vector <int> p = p_f(sub + "$" + main);
            for (int i = 0; i < p.size(); i++) {
                if (p[i] == sub.size()) {
                    v[sub]++;
                }
            }

            if (v[sub] > mx) mx = v[sub];
        }
        
        cout << mx << '\n';
        for (auto j: v) {   
            if (j.second == mx) {
                cout << j.first << '\n';
            }
        }
    }

    return 0;
}