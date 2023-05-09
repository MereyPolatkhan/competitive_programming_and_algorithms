#include <bits/stdc++.h>

using namespace std;

vector<int> g[10000];
int used[10000];
int color[10000];

void print(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -- ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {    
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; 
        y--;
        g[x].push_back(y);
        g[y].push_back(x);

    }

    print(m);

    return 0;
}