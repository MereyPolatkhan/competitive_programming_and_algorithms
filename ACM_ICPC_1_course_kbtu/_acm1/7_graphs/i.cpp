#include <bits/stdc++.h>

using namespace std;

#define sz 100007

int n, m;
vector<int> g[sz];
int used[sz];
int color[sz];
bool flag = true;

void dfs(int v, int c) {
    color[v] = c;
    for (int y : g[v]) {
        if (color[y] == 0) {
            if (c == 1) {
                dfs(y, 2);
            }
            else {
                dfs(y, 1);
            }
        }
        else if (color[y] == c) {
            flag = false;
            return;
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x); 
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, 1);
        }
    }

    if (flag) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}