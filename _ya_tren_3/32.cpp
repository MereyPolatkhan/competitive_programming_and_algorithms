#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

vector<int> g[N];
bool used[N];


vector<vector<int>> res;
vector<int> temp;
void dfs(int v) {
    temp.push_back(v);
    used[v] = true;
    for (int y : g[v]) {
        if (used[y] == false) {
            dfs(y);
        }
    }
}




int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            dfs(i);
            res.push_back(temp);
            temp.clear();
        }
    }


    cout << res.size() << "\n";
    for (auto i : res) {
        cout << i.size() << "\n";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }





    return 0;
}