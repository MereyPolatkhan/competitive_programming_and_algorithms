#include <bits/stdc++.h>


using namespace std;


int a[10000][10000];
int temp[10000][10000];
int n, m;

void fill() {
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++) {
            a[i][j] = -1;
            temp[i][j] = -1;
        }
    }
}

void print() {
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << " " ;
        }
        cout << "\n";
    }
}

void cinn() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                temp[i][j] = 0;
            }
        }
    }
}

void copy_to_a() {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = temp[n - i + 1][j];
        }
    }
}




int used[10000][10000];

void dfs(int y, int x, char napr_X, char napr_Y, int how = 1) {
    if (y >= 1 and y <= n and x >= 1 and x <= m and a[y][x] >= 0) {
        
        if (napr_X == '+' and napr_Y == 'D') {
            a[y + 1][x] = how;
            y++;
            x = x;
        }
        else if (napr_X == '+' and napr_Y == 'U') {
            a[y - 1][x] = how;
            y--;
            x = x;
        }
        else if (napr_X == 'R' and napr_Y == '+') {
            a[y][x + 1] = how;
            y = y;
            x++;
        }
        else if (napr_X == 'L' and napr_Y == '+') {
            a[y][x - 1] = how;
            y = y;
            x--;
        }
        else if (napr_X == 'L' and napr_Y == 'U') {
            a[y - 1][x - 1] = how;
            y--;
            x--;
        }
        else if (napr_X == 'R' and napr_Y == 'U') {
            a[y - 1][x + 1] = how;
            y--;
            x++;
        }
        else if (napr_X == 'L' and napr_Y == 'D') {
            a[y + 1][x - 1] = how;
            y++;
            x--;
        }
        else if (napr_X == 'R' and napr_Y == 'D') {
            a[y + 1][x + 1] = how;
            y++;
            x++;
        }
         
    }   
    else {
        return;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    fill();

    cinn();

    int sx, sy; cin >> sx >> sy;
    int tx, ty; cin >> tx >> ty;
    
    copy_to_a();

    dfs(sy, sx, '+', 'D');




    return 0;
}