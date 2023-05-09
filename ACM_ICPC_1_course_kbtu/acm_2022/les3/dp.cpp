#include <iostream>
#include <vector>
using namespace std;

int a[100][100];
int dp[100][100];

void solve() {
    vector<vector<int>> v = {
        {4, 3, 5, 1, 3},
        {5, 2, 1, 5, 1},
        {6, 2, 1, 4, 3},
        {7, 6, 4, 1, 5}
    };
    int n = v.size();
    int m = v[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 100;
        }
    }

    dp[0][0] = v[0][0];

    int dx[] = {-2, -2, 1, -1};
    int dy[] = {1, -1, -2, -2};
    
    for(int i = 1; i < n+m; i++) {
        int x = min(n-1, i);
        int y = max(i - n, 0);
        while(x >= 0 && y < m) {
            for(int j = 0; j < 4; j++) {
                int tox = dx[j] + x;
                int toy = dy[j] + y;
                if(tox >= 0 && tox < n && toy >= 0 && toy < m) {
                    dp[x][y] = min(dp[x][y], dp[tox][toy] + v[x][y]);
                } 
            }
            x -= 1;
            y += 1;
        }
    } 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}
int main() {
    solve();
}