#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i){ 
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    vector<int> a;

    int sift_up(int i) {
        while (i >= 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }

        return i;
    }

    void insert(int x){ 
        a.push_back(x);
        sift_up(a.size() - 1);
    }

    void print(){ 
        for (auto i: a) cout << i << " "; cout  << "\n";
    }

    int change(int index, int value) {
        a[index - 1] += value;
        return sift_up(index - 1) + 1;
    }
};

int main() {
    MaxHeap heap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.insert(x);
    }

    // heap.print();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int index, value;
        cin >> index >> value;
        cout << heap.change(index, value) << "\n";
    }

    heap.print();


    return 0;

}