#include <iostream>
#include <set>

using namespace std;


long long a[100];

int main() {
    freopen("arrange.in", "r", stdin);
    
    freopen("arrange.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n = 100;

    long long t;
    cin >> t;

    for (long long i = 0; i < t; i++) {
        string s;
        cin >> s;
        char c = s[0];
        long long san = (long long)c - 65;
        a[san]++;
    }

    if (a[0] == 0) {
        cout << 0;
        return 0;
    }

    long long k = 0;

    for (long long i = 0; i < n; i++) {
        if (a[i] != 0) {
            k++;
        }
        else {
            break;
        }
    }
    cout << k;

    return 0;
}