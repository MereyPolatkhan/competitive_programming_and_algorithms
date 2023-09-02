#include <bits/stdc++.h>


using namespace std;


#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n;
vector<vector<int>> graph;
vector<int> color, distinct;

vector<set<int>*> subtree;


void dfs(int i, int parent = -1) {
    int largest = -1;
    vector<int> children;
    for (int child: graph[i]) {
        if (child != parent) {
            dfs(child, i);
            children.pb(child);
            if (largest == -1 or subtree[largest]->size() < subtree[child]->size()) {
                largest = child;
            }
        }       
    }

    if (largest == -1) {
        subtree[i] = new set<int>; // leaf
    }
    else {
        subtree[i] = subtree[largest];
    }

    for (int ch: children) {
        if (ch == largest) {
            continue;
        }
        else {
            subtree[i]->insert(subtree[ch]->begin(), subtree[ch]->end());
        }
    }

    subtree[i]->insert(color[i]);
    distinct[i] = subtree[i]->size();
}

int main() {

    cin >> n;

    graph.resize(n);
    color.resize(n);
    distinct.resize(n);
    subtree.resize(n, NULL);
    

    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        cout << distinct[i] << " ";
    }


    return 0;
}