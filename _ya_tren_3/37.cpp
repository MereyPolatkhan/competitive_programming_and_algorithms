#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

int n;
vector<int> g[N];
vector<int> used(N, 0);
vector<int> d(N, 1e9);
vector<int> parent(N, -1);


void bfs(int v) {
    used[v] = 1;
    queue<int> q;
    q.push(v);
    d[v] = 0;

    while (q.size() > 0) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (used[y] == 0) {
                q.push(y);
                used[y] = 1;
                // d[y] = min(d[y], d[x] + 1);
                if (d[y] > d[x] + 1) {
                    d[y] = d[x] + 1;
                    parent[y] = x;
                }
            }
        }
    } 
}


int main() { 
    // freopen("input.txt", "r", stdin);   

    cin >> n;
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }


    int from, to;
    cin >> from >> to;

    bfs(from);

    if (d[to] >= 1e8) {
        cout << -1;
        return 0;
    }

    else if (d[to] == 0) {
        cout << 0;
        return 0;
    }
 
    cout << d[to] << "\n";


    vector<int> res;
    int i = to;
    while (i != -1) {
        res.push_back(i);
        i = parent[i];
    }

    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";


    return 0;
}