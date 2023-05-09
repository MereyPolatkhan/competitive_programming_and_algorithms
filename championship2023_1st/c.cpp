#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];
int used[1000][1000];
int n, m;


bool right(int i, int j) {
    if (j == m) {
        return true;
    }
    for (int jj = j + 1; jj <= m; jj++) {
        if (used[i][jj] == 0) {
            return false;
        }
    }
    return true;
}

bool up(int i, int j) {
    if (i == 1) {
        return true;
    }   
    for (int ii = i - 1; ii >= 1; ii--) {
        if (used[ii][j] == 0) {
            return false;
        }
    }
    return true;
}

bool left(int i, int j) {
    if (j == 1) {
        return true;
    }    
    for (int jj = j - 1; jj >= 1; jj--) {
        if (used[i][jj] == 0) {
            return false;
        }
    }
    return true;
}


bool down(int i, int j) {
    if (i == n) {
        return true;
    }
    for (int ii = i + 1; ii <= n; ii++) {
        if (used[ii][j] == 0) {
            return false;
        }
    }
    return true;
}



int main() {    

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j + 1] = int(s[j]) - int('0');
        }
    }

    vector<pair<int, int> > res;

    int all = 0;
    while(all < n * m) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (used[i][j] == 1) {
                    continue;
                }
                if (a[i][j] == 0) {
                    if (right(i, j)) {
                        // cout << i <<  " " << j << "\n";
                        res.push_back({i, j});
                        used[i][j] = 1;
                        cnt++;
                        all++;
                    }
                }
                else if (a[i][j] == 1) {
                    if (up(i, j)) {
                        // cout << i <<  " " << j << "\n";
                        res.push_back({i, j});
                        used[i][j] = 1;
                        cnt++;
                        all++;
                    }
                }
                else if (a[i][j] == 2) {
                    if (left(i, j)) {
                        // cout << i <<  " " << j << "\n";
                        res.push_back({i, j});
                        used[i][j] = 1;
                        cnt++;
                        all++;
                    }
                }
                else if (a[i][j] == 3) {
                    if (down(i, j)) {
                        // cout << i <<  " " << j << "\n";
                        res.push_back({i, j});
                        used[i][j] = 1;
                        cnt++;
                        all++;
                    }
                }
            }
        }

        if (cnt == 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for (auto i : res) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}