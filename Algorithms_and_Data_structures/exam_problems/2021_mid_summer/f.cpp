#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > pq;

    int n, mn;
    cin >> n >> mn;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq.push(x);
    }

    int cnt = 0;

    while (pq.top() < mn && pq.size() > 1) {
        int first_least = pq.top(); pq.pop();
        int second_least = pq.top(); pq.pop();

        int neww = first_least + 2 * second_least;

        pq.push(neww);
        cnt++;
    }

    if (pq.top() >= mn)
        cout << cnt;
    else 
        cout << -1;
    return 0;
}