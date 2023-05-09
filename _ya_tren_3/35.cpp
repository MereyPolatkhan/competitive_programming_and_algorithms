#include <bits/stdc++.h>


using namespace std;

#define N 100009
#define M 100009

int n;
vector<int> g[N];
vector<int> used(N, 0);
bool flag = false;
stack<int> st;
vector<int> res;

void dfs(int v, int parent) {
    used[v] = 1;
    st.push(v);
    for (int y : g[v]) {
        if (used[y] == 0) {
            dfs(y, v);
        }
        else if (parent != y and flag == false) {
            flag = true;
            while (st.top() != y and st.size() > 0) {
                res.push_back(st.top());
                st.pop();
            }
            res.push_back(st.top());
            return;
        }
    }
    if (st.size() > 0) st.pop();
    return;
}

int main() {    
    // freopen("input.txt", "r", stdin);

    cin >> n;
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }


    // int n, m;
    // cin >> n >> m;
    // for (int i = 1; i <= m; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     g[x].push_back(y);
    //     g[y].push_back(x);
    // }

    for (int i = 1; i <= n; i++){
        if (used[i] == false) {
            dfs(i, -1);
            while (st.size() > 0) st.pop(); // clear;
        }
    }


    if (flag == true) {
        cout << "YES\n" << res.size() << "\n";
        for (int i : res) {
            cout << i << " ";
        }
    }
    else cout << "NO\n";

    return 0;
}