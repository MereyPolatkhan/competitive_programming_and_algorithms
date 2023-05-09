#include <bits/stdc++.h>


using namespace std;


int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int res = 0;

    int cur = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i]) {
            cur++;
        }
        else {
            if (cur != 0) res++;
            cur = 0;
        }
    }
    if (cur != 0) res++;
    cout << res;


 
    return 0;
}