#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000];
vector<pair<int, pair<int, int>>> edges;
int par[1000];
int sz[1000];

void make_set() {
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = i;
    }
}

int find(int a) {
    if (a == par[a]) {
        return a;
    }
    int pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
        return;
    }

    if (sz[b] > sz[a]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}

int main() {
    cin >> n;
        
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int d = arr[i] + arr[j];
            edges.push_back({d, {i, j}});
        }
    }

    make_set();

    sort(edges.begin(), edges.end());

    vector<pair<int , int>> mst;

    int mst_sum = 0;

    for (auto &we: edges) {
        int w = we.first;
        pair<int, int> e = we.second;

        if (find(e.first) != find(e.second)) {
            mst.push_back(e);
            mst_sum += w;
            unite(e.first, e.second);
        }
    }

    cout << mst_sum;

    return 0;
}