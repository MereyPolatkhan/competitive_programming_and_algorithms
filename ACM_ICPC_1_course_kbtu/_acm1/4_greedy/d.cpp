#include <bits/stdc++.h>


using namespace std;


int main() {
    long long n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long> > pq;


    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    vector<long long> a;

    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        a.push_back(first + second);
        pq.push(first + second);
    }

    long long res = 0;
    for (auto i : a) res += i;
    cout << res;



    return 0;
}