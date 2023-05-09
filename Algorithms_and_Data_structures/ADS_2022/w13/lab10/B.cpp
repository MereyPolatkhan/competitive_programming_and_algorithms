#include <bits/stdc++.h>


using namespace std;

vector<int> g[1000];
bool used[1000];
int d[1000];

void bfs(int v){
    queue<int> q;
    q.push(v);
    used[v] = true;
    d[v] = 0;
    while (q.size() > 0) {
        int x = q.front();

        for (auto &y: g[x]) {
            if (used[y] == false) {
                q.push(y);
                used[y] = true;
                d[y] = d[x] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int A, B;
    cin >> A >> B;
    A--; B--;

    bfs(A);

    if (used[B] == false) cout << -1;
    else cout << d[B];


    return 0;
}