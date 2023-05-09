#include <bits/stdc++.h>
using namespace std;

vector<int> g[1018];
int mark[1018];

int x, y;
bool check;
void dfs(int v){
    mark[v] = 1;
    for(int u: g[v]){
        if (x == v && y == u) {
            continue;
        }
        if(!mark[u]){
            dfs(u);
        }
        if (mark[u] == 1) {
            check = 0;
            return;
        }
    }
    mark[v] = 2;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; i++) {
        for (int q : g[i]) {
            x = i, y = q;
            for(int j = 0; j < n; j++){
                mark[j] = 0;
            }
            check = 1;
            for (int j = 0; j < n; j++) {
                if (!mark[j]) {
                    dfs(j);
                }
            }
            if (check) {
                cout << "YES";
                return 0;
            }
        } 
    }
    cout << "NO";
}