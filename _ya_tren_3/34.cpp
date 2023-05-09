#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

vector<int> g[N];
vector<int> used(N, 0);

vector<int> topsort;
bool cycle = false;

void dfs(int v) {
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 0){
            dfs(i);
        }
        else if (used[i] == 1) {
            cycle = true;
            return;
        }
    }
    used[v] = 2;
    topsort.push_back(v);
}


int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }


    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            dfs(i);
        }
    }

    if (cycle) {
        cout << -1;
        return 0;
    }

    reverse(topsort.begin(), topsort.end());

    for (int i : topsort) cout << i << " ";

    return 0;
}