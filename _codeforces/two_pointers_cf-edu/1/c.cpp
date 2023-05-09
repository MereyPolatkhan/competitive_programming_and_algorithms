#include <bits/stdc++.h>

using namespace std;

int main() {    
    long long n, m;
    cin >> n >> m;
    
    vector<long long> a;
    vector<long long> b;

    unordered_map<long long, long long> mapa;
    unordered_map<long long, long long> mapb;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        mapa[x]++;
        if (a.size() == 0 || a.back() != x) a.push_back(x);
    }

    for (long long i = 0; i < m; i++) {
        long long x;
        cin >> x;
        mapb[x]++;
        if (b.size() == 0 || b.back() != x) b.push_back(x);
    }


    // for(long long i : a) cout << i << " "; cout << "\n";
    // for(long long i : b) cout << i << " "; cout << "\n";
    

    long long i = 0;
    long long j = 0;
    long long res = 0;
    while (i < a.size() and j < b.size()) {
        if (a[i] == b[j]) {
            res += (mapa[a[i]] * mapb[b[j]]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }

    while (i < a.size()) {
        if (a[i] == b[j]) {
            res += (mapa[a[i]] * mapb[b[j]]);
        }
        i++;
    }

    while (j < b.size()) {
        if (a[i] == b[j]) {
            res += (mapa[a[i]] * mapb[b[j]]);
        }
        j++;
    }
    cout << res;
    
    return 0;
}