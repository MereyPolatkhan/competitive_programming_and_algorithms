#include <bits/stdc++.h>
 
using namespace std;
 
bool cmp(pair<string,long long> a, pair<string,long long> b) {
    
    return a.second > b.second;
}
 
 
int main() {
 
    freopen("bad.in", "r", stdin);
    
    freopen("bad.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    long long n, m;
    cin >> n >> m;
 
    vector<pair<string, long long> > a;
    for (long long i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back({s, 0});
    }
 
    long long inv = 0;
    for (long long kk = 0; kk < m; kk++) {
        string s;
        cin >> s;
 
        long long index;
        long long k = 0;
 
        for (long long i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                k++;
                index = i;
            }
        }
        if (k != 1) {
            inv++;
        }
        else {
            a[index].second += 1;
        }
    }
 
    sort(a.begin(), a.end(), cmp);
 
    for (auto i: a) {
        double vote = i.second * (100.0 / m);
        cout << fixed;
        cout << i.first << " " << setprecision(2) << vote << "%\n";
    }
 
    cout << "Invalid " << setprecision(2) << inv * (100.0 / m) << "%\n";
    
    return 0;
}