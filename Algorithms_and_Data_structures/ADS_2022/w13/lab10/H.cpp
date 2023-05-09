#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[107][107];
int cnt = 0;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == 0) {
        return;
    }

    a[i][j] = 0;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {    
    cin >> n >> m;
    
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = (int)s[j] - (int)'0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;

    return 0;
}