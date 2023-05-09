#include <iostream>
#include <vector>

using namespace std;

struct MaxHeap {
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

    void insert(int x){ 
        a.push_back(x);
        int i = a.size() - 1;
        sift_up(i);
    }

    void sift_up(int i) {
        while (i >= 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int j = left(i);
        
        if (j > sz() - 1) {
            return;
        }

        if (right(i) <= sz() - 1 && a[right(i)] > a[left(i)]) {
            j = right(i);
        }

        if (a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extract_max() {
        int max = a[0];
        swap(a[0], a[sz() - 1]);
        a.pop_back();
        if (sz() > 0) {
            heapify(0);
        }
        return max;
    }

    int sz() {
        return a.size();
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    MaxHeap m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        m.insert(x);
    }

    long long s = 0;

    for (int i = 0; i < k; i++) {
        int max = m.extract_max();
        s += max;
        m.insert(max - 1);
    }

    cout << s;
    return 0;
}