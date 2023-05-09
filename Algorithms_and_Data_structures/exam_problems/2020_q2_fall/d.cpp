#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    while(n--) {
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() < 3) {
            cout << -1 << "\n";
        }
        else {
            int prod = 1;
            int a[3];
            for (int i = 0; i < 3; i++) {
                a[i] = pq.top();
                prod *= a[i];
                pq.pop();
            }
            cout << prod << "\n";
            for (int i = 0; i < 3; i++) {
                pq.push(a[i]);
            }
        }
    }    

    return 0;
}