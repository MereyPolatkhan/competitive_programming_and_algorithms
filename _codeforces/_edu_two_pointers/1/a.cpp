#include <bits/stdc++.h>

using namespace std;

int main() {    
    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];


    int c[n + m];
    int i = 0; 
    int j = 0;
    int k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        c[k] = a[i];
        k++;
        i++;
    }

    while (j < m) {
        c[k] = b[j];
        k++;
        j++;
    }

    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }


    return 0;
}