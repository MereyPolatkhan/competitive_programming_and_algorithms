#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1007][1007];
bool used[1007][1007];
queue< pair<int, int > > Q;

int res = 0;
int mushrooms = 0;
int eated = 0;

void bfs() {
    while (Q.empty() == false){
        queue< pair<int, int > > q;
        while (Q.empty() == false) {
            int el_x = Q.front().first;
            int el_y = Q.front().second;
            Q.pop();
            q.push({el_x, el_y});
        }

        while (q.empty() == false)  {
            pair<int, int> current = q.front();
            q.pop();

            int i = current.first;
            int j = current.second;

            if (i + 1 < n && a[i + 1][j] == 1) {
                eated++;
                Q.push({i + 1, j});
                a[i + 1][j] = 2;
            }
            if (j + 1 < m && a[i][j + 1] == 1) {
                eated++;
                Q.push({i, j + 1});
                a[i][j + 1] = 2;
            }
            if (i - 1 >= 0 && a[i - 1][j] == 1) {
                eated++;
                Q.push({i - 1, j});
                a[i - 1][j] = 2;
            }
            if (j - 1 >= 0 && a[i][j - 1] == 1) {
                eated++;
                Q.push({i, j - 1});
                a[i][j - 1] = 2;
            }
        }
        res++;
    }
}


int main() {
    cin >> n >> m;

    int x, y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                Q.push({i, j});  
            }
            if (a[i][j] == 1) {
                mushrooms++;
            }
        }
    }
    if (Q.size() == 0 && mushrooms == 0) {
        cout << 0;
        return 0;
    }
    else { 
        bfs();
    }
    if (eated == mushrooms) {
        cout << res - 1;
    }
    else {
        cout << -1;
    }
    
    return 0;
}