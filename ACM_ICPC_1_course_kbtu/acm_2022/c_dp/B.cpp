#include <iostream>

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int delta = 0;
    
    for (int i = 1; i < n; i++) {
        delta += max(0, k - a[i] - a[i - 1]);
        a[i] += max(0, k - a[i] - a[i - 1]);   
    }
    cout << delta << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }

    return 0;
}