// Полное решение
#include <bits/stdc++.h>

using namespace std;

bool check(string s, string t, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R' && t[i] == 'G') {
            return false;
        }
        else if (s[i] == 'R' && t[i] == 'B') {
            return false;
        }
        if (s[i] == 'B' && t[i] == 'R') {
            return false;
        }
        if (s[i] == 'G' && t[i] == 'R') {
            return false;
        }
    }
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n; 
        cin >> n;
        
        string s1, s2;
        cin >> s1 >> s2;
        if (check(s1, s2, n) == true){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}