#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
bool used[100005];
int cnt = 0;

map<int, int> parents;
map<int, int> childrens;

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    used[v] = true;
    while(Q.size() > 0){
        queue<int> q;
        while (Q.size() > 0) { 
            q.push(Q.front());
            Q.pop();
        }

        while (q.size() > 0) {
            int x = q.front();
            q.pop();
            int cur_cnt_of_childrens = 0;
            for (auto cnt: g[x]) {
                if (used[cnt] == false) {
                    cur_cnt_of_childrens++;
                }
            }
            childrens[x] = cur_cnt_of_childrens;

            for (auto to: g[x]) {
                if (used[to] == false){
                    parents[to] = x;
                    Q.push(to);
                    used[to] = true;
                }
            }
        }
    }
}

bool check(int child, int parent) {
    return (childrens[child] > childrens[parent]);
}

int main(){
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){ 
        if (used[i] == false) {
            cnt++;
            bfs(i);
        }
    }

    // for (auto i: parents) {
    //     cout << "parent of " << i.first + 1<< " is  " << i.second  + 1<< "\n"; 
    // }
    // cout << "\n";
    // for (auto i: childrens) {
    //     cout << i.first + 1<< " has " << i.second << " children\n"; 
    // }


    for (auto i: parents) {
        if (check(i.first, i.second)) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}