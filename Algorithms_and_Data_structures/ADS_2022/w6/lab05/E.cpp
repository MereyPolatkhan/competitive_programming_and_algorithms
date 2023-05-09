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



int main() {
    long long q, k;
    cin >> q >> k;
    
    while(k--) {
        insert(0);
    }

    while (q--) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long x;
            cin >> x;
            if (get_min() < x) {
                extract_min();
                insert(x);
            }
        }
        else {
            long long sum = 0;
            for (auto i: a) sum += i;
            cout << sum << "\n";
        }

    }

    return 0;
}