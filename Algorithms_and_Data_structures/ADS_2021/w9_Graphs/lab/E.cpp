// accepted
#include <iostream>
#include <vector> 

using namespace std;
// graph ==> tree:
// - There is no cycle. 
// - The graph is connected

int n;
vector<int> a[11111];
bool used[11111];

bool is_cycle(int v, int parent) {  
    used[v] = true;
    for (auto i: a[v]) {
        if (used[i] == false) {
            bool again = is_cycle(i, v);
            
            if (again == true) {
                return true;
            }
        }   
        else { // used = true
            if (i != parent) {
                return true;
            }
        } 
    }

    return false;
}

bool is_connected() {
    for(int i = 0; i < n; i++) {
        if (used[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; 
            cin >> x;
            if (x == 1) a[i].push_back(j);
        }
    }

    if (is_cycle(0, -1) == true) {
        cout << "NO";
    }
    else if (is_connected() == false) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}