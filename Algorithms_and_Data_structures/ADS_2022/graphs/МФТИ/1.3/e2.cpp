#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1000];

void print() {
    for (int i = 1; i < 6; i++) {
        cout << i << "----- ";
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

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int c;
    cin >> c;

    // print();

    cout << g[c].size();
    return 0;
}