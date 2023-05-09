#include <bits/stdc++.h>

using namespace std;

vector<int> g[100000];

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int x; int y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    

    
    return 0;
}