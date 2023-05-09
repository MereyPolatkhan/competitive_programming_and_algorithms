#include <iostream> 
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    int a[t];

    for (int i = 0; i < t; i++) { // O(t)
        cin >> a[i];
    }


    int n, m;
    cin >> n >> m;
    int snake[n][m];

    for (int i = 0; i < n; i++) { // O(n*m)
        for (int j = 0; j < m; j++) {
            cin >> snake[i][j]; 
        }
    }

    vector <pair <int, pair<int, int>>> v;
    int x;
    for (int i = 0; i < n; i++) { // O(n*m)
        if (i % 2 == 0){
            for (int j = 0; j < m; j++) {
                x = snake[i][j];
                v.push_back({x, {i, j}});
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                x = snake[i][j];
                v.push_back({x, {i, j}});
            }
        }
    }
     


    // 25 23 20 19 18 17 15 13 12 10 9 8
    // 10 15 13 8 23

    for (int i = 0; i < t; i++) { 
        // size of v = n*m;
        // to find one el = O(log(n*m))
        // to find t el =RES= O(t * log(n*m))
        int num = a[i];
        
        int l = 0;
        int r = v.size() - 1;

        bool flag = false;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid].first == num) {
                cout << v[mid].second.first << " " << v[mid].second.second << "\n";
                flag = true;
                break;
            }
            else if (v[mid].first < num) {
                r = mid - 1;
            }
            else if (v[mid].first > num) {
                l = mid + 1;
            }
        }
        if (flag == false) cout << -1 << "\n";
    }

    // Overall = O(t) + O(n*m) + O(n*m) + O(t * log(n*m)) == ??
    return 0;
}