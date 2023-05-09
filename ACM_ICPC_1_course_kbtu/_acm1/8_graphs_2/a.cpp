#include <bits/stdc++.h>

using namespace std;

#define N 20007
#define M 200007

vector<int> g[N];
vector<int> gr[N];
vector<char> used(N, false);
vector<int> order, component;
int n, m; 
vector<vector<int>> res;

void dfs1(int v) {
    used[v] = true;
    for (int to: g[v]) {
        if (used[to] == false) {
            dfs1(to);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int to: gr[v]) {
        if (used[to] == false) {
            dfs2(to);
        }
    }
}


int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            dfs1(i);
        }
    }
    
    used.assign(N, false);
    for (int i = 1; i <= n; i++) {
        int v = order[n - i];
        if (used[v] == false) {
            dfs2(v);
            res.push_back(component);
            // for (int i : component) { 
            //     cout << i << " ";
            // }
            // cout << "\n";
            component.clear();
        }
    }

    cout << res.size() << "\n";
    vector<int> ans(N, 0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            ans[res[i][j]] = i + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}