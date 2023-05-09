#include <iostream>
#include <vector>

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



long long sum = 0;
long long res = 0;

void solve() {
    while (a.size() != 1) {
        long long min1 = extract_min();
        long long min2 = extract_min();
        sum = min1 + min2;
        insert(sum);
        res += sum;
    }
}

int main() {

    long long n;
    cin >> n;

    while (n--){
        long long x;
        cin >> x;
        insert(x);
    }

    solve();
    cout << res;

    return 0;
}