#include <bits/stdc++.h>

using namespace std;

void func(string a[], string b[], string c[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    } cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    } cout << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    } cout << endl;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int j = 0; j < t; j++) {
        int n; 
        cin >> n;
        string a[n], b[n], c[n];
        
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            a[i] = s;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            b[i] = s;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            c[i] = s;
        }
        
        sort(a, a + n);
        sort(b, b + n);
        sort(c, c + n);
        
        func(a, b, c, n);
    }
 
    return 0;
}