// Задача №767. Похожие массивы

#include <bits/stdc++.h> 

using namespace std;

int remove_duplicates(int a[], int n) {
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            a[j] = a[i];
            j++;
        }
    }
    a[j] = a[n - 1];
    return j;
}

int main() {
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

//
    sort(a, a + n);
    sort(b, b + m);
//
    n = remove_duplicates(a, n);
    m = remove_duplicates(b, m);

    if (n != m) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
     

    return 0;
}