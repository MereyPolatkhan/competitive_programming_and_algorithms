#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int mark[100005];

bool cycle = false;



void dfs(int v){ 
    mark[v] = 1;
    for (auto y: g[v]) {
        if (mark[y] == 0) {
            dfs(y);
        }
        else if (mark[y] == 1) {
            cycle = true;
            return;
        }
    }

    mark[v] = 2;
}

void del(int x, int y) {
    swap(g[x][g[x].size() - 1], g[x][y]);
    g[x].pop_back();
}

void add(int x, int y) {
    g[x].push_back(y);
}


void print(int n) {
    for (int i = 0; i < n; i++) {
    cout << i + 1<< "------";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] + 1<< " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x--; y--;

        add(x, y);
    }
    del(2-1, 1-1);

    // print(n);
    cycle = false;
    for (int i = 0; i < n; i++ ){
        mark[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    if (cycle == true) cout << "cycle";
    else cout << "NO";
    return 0;
}
