#include <bits/stdc++.h>


using namespace std;


#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 7;







int n;
vector<vector<int>> g(MAXN);
vector<map<int, int>> cnt(MAXN);

vector<int> color(MAXN);
vector<int> id(MAXN);
vector<ll> res(MAXN);

int mx[MAXN];
ll sum[MAXN];

void combine(int idi, int idto) {
    for (auto  &it: cnt[idto]) {
        if (mx[idi] == cnt[idi][it.first]) {
            cnt[idi][it.first] += it.second;
            mx[idi] = cnt[idi][it.first];
            sum[idi] = it.first;
        }
        else {  
            cnt[idi][it.first] += it.second;
            if (cnt[idi][it.first] == mx[idi])
                sum[idi] += it.first;
            else if (cnt[idi][it.first] > mx[idi]) {
                mx[idi] = cnt[idi][it.first];
                sum[idi] = it.first;
            }
        }
    }
}

void dfs(int i, int parent = -1) {
    id[i] = i;
    cnt[id[i]][color[i]]++;
    mx[id[i]] = 1;
    sum[id[i]] = color[i];

    for (int to: g[i]) {
        if (to == parent) 
            continue;
        dfs(to, i);
        if (cnt[id[i]].size() < cnt[id[to]].size()) {
            swap(id[i], id[to]);
        }
        combine(id[i], id[to]);
    }

    res[i] = sum[id[i]];
}

int main() {

    cin >> n;    

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }


    return 0;
}