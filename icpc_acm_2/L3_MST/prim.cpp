#include <iostream>
#include <vector>
const int MAX_INT = 1e7;

using namespace std;
vector<int> d(100, MAX_INT);
int n, m, x, y, l;
int g[100][100];
int used[100];
int c[100];

int main() {

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--; y--;
        g[x][y] = l;
        g[y][x] = l;
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || d[v] > d[j]))
                v = j;
        }
        used[v] = true;
        // cout << v + 1 << endl;
        for (int j = 0; j < n; j++) {
            if (!used[j] && g[v][j] && d[j] > g[v][j]) {
                d[j] = g[v][j];
                c[j] = v;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << c[i] + 1 << endl;
    return 0;
}