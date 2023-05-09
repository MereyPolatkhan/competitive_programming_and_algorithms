#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) * 2 + 7;

int par[N], sz[N];

int n, m;

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
    cin >> n >> m;

    map<int, vector<int>> mp;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);

        mp[x].push_back(y);
    }
    
    make();

    vector<int> ans;
    int cnt = 0;

    for (int i = n; i >= 1; i--) {
        ans.push_back(cnt);
        cnt++;

        if (mp.count(i) != 0) {
            for (auto y: mp[i]) {
                int xpar = find(i);
                int ypar = find(y);
                if (xpar != ypar) {
                    cnt--;
                    par[xpar] = ypar;
                }
            }
        }    
    }
    reverse(ans.begin(), ans.end());
    for (auto i: ans) cout << i << "\n";
    return 0;   
}