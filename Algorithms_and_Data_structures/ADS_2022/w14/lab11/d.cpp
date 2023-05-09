#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
int n;
int par[100], sz[100];

int find(int a){
    if (a == par[a]) {
        return a;
    }
    int pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;

    sz[a] += sz[b];
}

void make(){
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
}

int main() {    
    cin >> n;   
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({a[i][j], {i + 1, j + 1}});
        }
    }

    sort(edges.begin(), edges.end());

    make();

    int sum = 0;

    for (auto we: edges) {
        int x = we.second.first;
        int y = we.second.second;
        int w = we.first;

        if (find(x) != find(y)) {
            sum += w;
            unite(x, y);
        }
    }
    cout << sum;

    return 0;
}