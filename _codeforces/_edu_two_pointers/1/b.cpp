#include <bits/stdc++.h>

using namespace std;

int main() {    
    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> res;

    int i = 0, j = 0;
    while (i < n and j < m) {
        if (a[i] < b[j]) {
            i++;
        }
        else {
            res.push_back(i);
            j++;
        }
    }
 
    while (j < m){
        res.push_back(i);
        j++;
    }

    for (int i: res) cout << i << " ";
    return 0;
}