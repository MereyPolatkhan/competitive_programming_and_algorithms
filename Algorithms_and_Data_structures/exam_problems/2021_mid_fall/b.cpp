#include <bits/stdc++.h>


using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int> > pq;

    int n;
    cin >> n;



    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int sum = 0;

    while (pq.size() != 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int cur_sum = first + second;
        sum += cur_sum;
        pq.push(cur_sum);
    }

    cout << sum;


    return 0;

}