#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

int n;
vector<int> g[N];
vector<int> used(N, 0);
bool flag = false;

void dfs(int v, int parent) {
    used[v] = 1;
    for (int y : g[v]) {
        if (used[y] == 0) {
            dfs(y, v);
        }
        else if (parent != y and flag == false) {
            flag = true;
            return;
        }
    }
    return;
}

int main() {    
    // freopen("input.txt", "r", stdin);


    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++){
        if (used[i] == false) {
            dfs(i, -1);
        }
    }


    if (flag == false) {
        cout << "YES\n";
    }
    else cout << "NO\n";

    return 0;
}