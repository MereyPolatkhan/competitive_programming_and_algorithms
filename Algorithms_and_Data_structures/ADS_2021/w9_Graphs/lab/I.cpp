#include <bits/stdc++.h> 

using namespace std;

vector<pair<int, int>> res;
int n;
vector<int> a[111111];
int d[111111];
bool used[11111];

void bfs(int v) {
    queue<int> q;
    used[v] = true;
    q.push(v);
    d[v] = 0;

    while(q.size() > 0) {
        int x = q.front();
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (used[y] == false) {
                q.push(y);
                used[y] = true;
                d[y] = d[x] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) d[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1) {
                a[i].push_back(j);
            }
        }
    }

    int begin, end;
    cin >> begin >> end;
    begin--; end--;

    bfs(begin);


    for (int i = 0; i < n; i++) {
        res.push_back({d[i], i});
    }
    // sort(res.begin(), res.end());
    for (auto i: res) {
        cout << "d[i] = " << i.first << " || ";
        cout << "i  = " << i.second << endl;
    }

    for (auto i: res) {
        
    }
    return 0;   
}