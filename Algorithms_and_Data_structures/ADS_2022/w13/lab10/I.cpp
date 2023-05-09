#include <bits/stdc++.h>

using namespace std;

const int N = 100007;

vector<int> res;
vector<int> g[N];
int mark[N];
bool check = false;

void dfs(int v) {
    mark[v] = 1;

    for (int y: g[v]) {
        if (mark[y] == 0) {
            dfs(y);
        }
        else if (mark[y] == 1) {
            check = true;
            return;
        }
    }
    mark[v] = 2;
    res.push_back(v);
}

void run(int n) {
    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    reverse(res.begin(), res.end());
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    run(n);

    if (check) {
        cout << "Impossible\n";
    }
    else {
        cout << "Possible\n";
        for (int i: res) cout << i + 1 << " ";
    }


    return 0;
}