#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 7;
int par[N], sz[N];

vector<pair<int, pair<int, int>>> edges;
int n, m;

void make(){
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

void print(){
    for (auto i: edges) {
        cout << i.second.first << " " << i.second.second << " " << i.first << "\n";
    }
    cout << "\n";
}

int find(int a){ 
    int parent = par[a];
    if (parent == a) {
        return a;
    }
    int p = find(parent);
    par[a] = p;
    return p;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (sz[b] > sz[a])
		swap(a, b);
	// merge b to a
	par[b] = a;
	sz[a] += sz[b];

}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int big, small;
    cin >> big >> small;

    int both = min(big, small);

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        int x, y, w; cin >> x >> y >> w;
        
        if (s == "both") w = w * both;
        else if (s == "small") w = w * small;
        else w = w * big;

        edges.push_back({w, {x, y}});
    }

    sort(edges.begin(), edges.end());

    make();

    vector<pair<int, int>> mst;
    int sum = 0;
    for (auto el: edges) {
        int x = el.second.first;
        int y = el.second.second;
        int w = el.first;

        if (find(x) != find(y)) {
            mst.push_back({x, y});
            sum += w;
            unite(x, y);
        }
    }
    cout << sum;


    return 0;
}