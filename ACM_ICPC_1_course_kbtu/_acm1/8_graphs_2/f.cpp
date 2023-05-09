#include <bits/stdc++.h>

using namespace std;

#define MXN 100007

int timer = 0;
vector<int> tin(MXN, 0);
vector<int> fup(MXN, 0);
vector<bool> used(MXN, false);
vector<pair<int, int> > bridges;
vector<int> g[MXN];

int cases = 0;

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				bridges.push_back({::min(v, to), ::max(v, to)});
		}
	}
}

void construct_graph(int n) {
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        string s;
        cin >> s;

        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (i != 0 and i != s.size() - 1) {
                s1 += s[i];
            }
        }

        int k = stoi(s1);
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            g[v].push_back(x);
        }

    }
}

void s() {
    int n;
    cin >> n;

    construct_graph(n);

    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            dfs(i);
        }
    }

    sort(bridges.begin(), bridges.end());

    cout << "Case " << ++cases << ":\n";
    cout << bridges.size() << " critical links\n";
    for (auto &x : bridges) cout << x.first << " - " << x.second << "\n";


    timer = 0;
    tin.assign(MXN, 0);
    fup.assign(MXN, 0);
    used.assign(MXN, false);

    bridges.clear();
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        s();
    }

    return 0;
}