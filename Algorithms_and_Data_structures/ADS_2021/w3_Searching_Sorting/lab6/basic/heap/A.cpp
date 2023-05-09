// Задача №754. Пирамидальная сортировка

#include <iostream> 
#include <vector>

using namespace std;

// Global Array 
vector <int> a;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return (2 * i + 1);
}

int right(int i) {
    return (2 * i + 2);
}

void heapify(int i) {
    if (left(i) > a.size() - 1)
        return;
        
    int j = left(i);
    if (right(i) < a.size() && a[left(i)] > a[right(i)])
        j = right(i);

    if (a[i] > a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
}

int extract_min() {
    int min = a[0];
    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if (a.size() > 0) 
        heapify(0);
    return min;
}

void sift_up(int i) {
    while (i > 0 && a[parent(i)] > a[i]) {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

void insert(int x) {
    a.push_back(x);
    int i = a.size() - 1;

    sift_up(i);
}

void Heap_Sort(int b[], int size_of_b) {
    for (int i = 0; i < size_of_b; i++) {
        insert(b[i]);
    }

    for (int i = 0; i < size_of_b; i++) {
        b[i] = extract_min();
    }
    
}

int main() {

    int n;
    cin >> n;

    int b[n];

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    Heap_Sort(b, n);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}