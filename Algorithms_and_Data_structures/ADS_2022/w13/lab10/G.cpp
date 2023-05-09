#include <bits/stdc++.h>


using namespace std;

vector<int> g[100005];
int mark[100005];
bool cycle = false;

stack<int> st;
vector<int> cyclePath;

void dfs(int v){
    mark[v] = 1;
    st.push(v);
    for (auto y: g[v]) {
        if (mark[y] == 0) {
            dfs(y);
        }
        else if (mark[y] == 1 && cycle == false) {
            cycle = true;
            while (st.top() != y) {
                cyclePath.push_back(st.top());
                st.pop();
            }
            cyclePath.push_back(y);
            cyclePath.push_back(v);
            reverse(cyclePath.begin(), cyclePath.end());
            return;
        }
    }
    mark[v] = 2;
    if (st.size() > 0) st.pop();
}

void del(int x, int y) {
    int ind = 0;
    for (int i = 0; i < g[x].size(); i++) {
        if (g[x][i] == y) {
            ind = i;
            break;
        }
    }
    swap(g[x][ind], g[x][g[x].size() - 1]);
    g[x].pop_back();
}

void add(int x, int y) {
    g[x].push_back(y);
}


void dfs2(int v){
    mark[v] = 1;
    for (auto y: g[v]) {
        if (mark[y] == 0) {
            dfs2(y);
        }
        else if (mark[y] == 1) {
            cycle = true;
            return;
        }
    }
    mark[v] = 2;
}
void print(int n) {
    for (int i = 0; i < n; i++) {
    cout << i + 1<< "------";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] + 1<< " ";
        }
        cout << "\n";
    }
    cout << "\n";
}



int main() {
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }

    if (cycle == false) {
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < cyclePath.size() - 1; i++) {
        int x = cyclePath[i];
        int y = cyclePath[i + 1];

        del(x, y);
        

        cycle = false;
        for (int j = 0; j < n; j++) mark[j] = 0;


        for (int j = 0; j < n; j++) {
            if (mark[j] == 0) {
                dfs2(j);
            }
        }

        if (cycle == true) {
            add(x, y);
        }
        else {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;
}