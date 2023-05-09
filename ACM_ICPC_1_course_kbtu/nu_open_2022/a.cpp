#include <bits/stdc++.h>


using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;

    if (k * k == a * a + b * b) {
        cout << "YES";
        return 0;
    }
    if (a * a == k * k + b * b) {
        cout << "YES";
        return 0;
    }
    if (b * b == a * a + k * k) {
        cout << "YES";
        return 0;
    }
    cout << "NO";



    return 0;
}