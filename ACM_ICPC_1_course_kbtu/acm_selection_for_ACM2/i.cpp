#include <bits/stdc++.h>

using namespace std;

string generator(int n0, int n1, int n2) {
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << generator(a, b, c) << "\n";
    }

    return 0;
}