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

    string s, t;
    cin >> s >> t;

    string q = s + "$" + t + t;


    vector<int> p = p_f(q);

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == s.size()) {
            cout << i - s.size() - t.size();
            return 0;
        }
    } 

    cout << -1;


    return 0;
}