#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];

    for (int ii = 0; ii < n; ii++) cin >> a[ii];


    int m;
    cin >> m;
    int b[m];
    for (int ii = 0; ii < m; ii++) cin >> b[ii];



    int res[n + m];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            res[k] = a[i];
            i++;
            k++;
        }
        else {
            res[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < n) {
        res[k] = a[i];
        k++;
        i++;
    }

    while (j < m) {
        res[k] = b[j];
        k++;
        j++;
    }

    for (int ii = 0; ii < n + m; ii++) {
        cout << res[ii] << " ";
    }

    return 0;
}