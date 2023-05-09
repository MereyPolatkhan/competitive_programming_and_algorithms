#include <bits/stdc++.h> 

using namespace std;

vector<int> g[1000];
bool used[1000];

bool is_cycle(int v, int parent) {
    used[v] = true;
    for (auto sosedy: g[v]) {
        if (used[sosedy] == false){ 
            if (is_cycle(sosedy, v) == true) {
                return true;
            }
        }
        else {
            if (sosedy != parent) {
                return true;
            }
        }
    }
    return false;
}

bool is_connected(int n) {
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }


    if (is_cycle(0, -1) == false && is_connected(n) == true) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}