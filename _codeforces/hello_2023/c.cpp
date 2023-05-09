#include <bits/stdc++.h>

using namespace std;

void calc_pref(int * b, int n) {
    for (int i = 1; i < n; i++) {
        b[i] = b[i] + b[i - 1];
    }
}

void show(int * b, int n) {
      for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

void solve() {
    int res = 0;
    int n, m;
    cin >> n >> m;
    m -= 1;
   
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    calc_pref(p, n);

    int x_index = -1;
    int pxmin = p[0];
    for (int i = 0; i < m; i++) {
        if (pxmin > p[i] && p[m] > p[i]) {
            pxmin = p[i];
            x_index = i;
        }
    }

    if (x_index != -1) {
        priority_queue <int> maxHeap;
        for (int i = x_index + 1; i <= m; i++) {
            maxHeap.push(p[i]);
        }

        while (true) {
            if (p[m] <= pxmin) {
                break;
            }
            int tp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(tp * (-1));
            res++;
        }
    }
    
    priority_queue <int, vector<int>, greater<int>> minHeap;
    for (int i = m + 1; i < n; i++) {
        minHeap.push(p[i]);
    }

    while (true) {
        if (p[m] <= minHeap.top()) {
            break;
        }
        int tpp = minHeap.top();
        minHeap.pop();
        minHeap.push(tpp * (-1));
        res++;
    }

    cout << res << "\n";
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}