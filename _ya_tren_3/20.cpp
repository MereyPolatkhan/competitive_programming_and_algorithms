#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
 
    priority_queue <int, vector<int>, greater<int>> minHeap;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        minHeap.push(x);
    }

    while (minHeap.size() > 0) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}