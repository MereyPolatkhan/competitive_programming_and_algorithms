#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void sift_up(int i) {
    while (i > 0 && a[parent(i)] < a[i]) {
        int j = parent(i);
        swap(a[j], a[i]);
        i = j;
    }
}

void insert(int x) {
    a.push_back(x);
    sift_up(a.size() - 1);
}

void heapify(int i) {
    if (left(i) > a.size() - 1) {
        return;
    }
    int j = left(i);
    if (right(i) < a.size() && a[left(i)] < a[right(i)]) {
        j = right(i);
    }
    if (a[i] < a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
}

int extract() {
    int res = a[0];
    swap(a[0], a[a.size() - 1]);
    a.pop_back();

    if (a.size() > 0) {
        heapify(0);
    }
    
    return res;
}


int main() {
    // freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    while (t--){ 
        int k; 
        cin >> k;
        if (k == 0) {
            int n;
            cin >> n;
            insert(n); 
        }
        else {
            cout << extract() << "\n";
        }
    }

    return 0;
}