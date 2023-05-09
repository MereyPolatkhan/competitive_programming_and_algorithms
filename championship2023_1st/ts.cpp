#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int utc = 11 + (n - 6);
    if (utc < 0) {
        utc = 24 + utc;   
    }

    if (utc == 24) {
        cout << "00:00" << "\n";
    }
    else if (utc >= 10) {
        cout << utc << ":00" << "\n";
    }
    else {
        cout << "0" << utc << ":00" << "\n";
    }
}

int main() {
cout << 14 /5 ;
    return 0;
}