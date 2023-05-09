#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000];
int used[1000];

void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -- ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}


int cnt = 0;
void dfs(int v) {
    cnt++;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0){
            dfs(y);
        }
    }
}

int main(){
    int n;
    cin >> n;

    int s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }

    
    // print(n);

    dfs(s - 1);
    cout << cnt;
    return 0;
}