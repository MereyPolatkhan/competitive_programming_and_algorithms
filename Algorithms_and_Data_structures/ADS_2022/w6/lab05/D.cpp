#include <bits/stdc++.h>

using namespace std;

vector<long long> a;

long long parent(long long i){ 
    return (i - 1) / 2;
}

long long left(long long i) {
    return 2 * i + 1;
}

long long right(long long i) {
    return 2 * i + 2;
}

void sift_up(long long i) {
    while (i >= 0 && a[parent(i)] > a[i]) {
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

void insert(long long x){
    a.push_back(x);
    long long last_i = a.size() - 1;
    sift_up(last_i); 
}

void heapify(long long i) {
    long long last_i = a.size() - 1;
    if (left(i) > last_i) {
        return;
    }
    long long j = left(i);
    if (right(i) <= last_i && a[left(i)] > a[right(i)]) {
        j = right(i);
    }
    if (a[i] > a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
}


long long get_min() {
    return a[0];
}

long long extract_min() {
    long long min = get_min();
    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if (a.size() > 0) {
        heapify(0);
    }
    return min;
}


long long k = 0;
long long solve(long long m) {
    while (a.size() > 1) {
        if (get_min() >= m) {
            return k;
        }
        else {
            long long first = extract_min();
            long long second = extract_min();
            long long d = first + 2 * second;
            k++;
            insert(d);
        }
    }
    return -1;
}

int main() {

    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        insert(x);
    }

    cout << solve(m);
    

    return 0;
}