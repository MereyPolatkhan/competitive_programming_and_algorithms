// accepted
#include <bits/stdc++.h> 

using namespace std;

int n, m;
vector<int> a[111111];
bool used[111111];
vector<int> component;

vector<vector<int>> res;

void dfs(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < a[v].size(); i++) {
        int y = a[v][i];
        if (used[y] == false) {
            dfs(y);
        }
    }
}

void func() {
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            component.clear();
            dfs(i);
            res.push_back(component);
        }
    }
    
    cout << res.size() << "\n";

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].size() << "\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] + 1 << " ";
        }
        cout << "\n";;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    
    // n - vertices
    // m - edges 

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    func();

    return 0;
}