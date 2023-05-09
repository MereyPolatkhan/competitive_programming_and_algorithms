#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    int b;
    cin >> b;

    bool b1 = (a1 == a2) && (a2 == a3) && (a3 == a4);
    bool b2 = (a1 + b == a2) && (a2 == a3) && (a3 == a4);
    bool b3 = (a1 == a2 + b) && (a2 + b == a3) && (a3 == a4);
    bool b4 = (a1 == a2) && (a2 == a3 + b) && (a3 + b == a4);
    bool b5 = (a1 == a2) && (a2 == a3) && (a3 == a4 + b);

    if (b1 == 1 || b2 == 1 || b3 == 1 || b4 == 1 || b5 == 1) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}