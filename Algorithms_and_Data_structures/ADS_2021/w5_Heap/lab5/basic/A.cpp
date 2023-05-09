#include <iostream> 
#include <vector> 

using namespace std;

class Max_Heap {
public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){ 
        return 2 * i + 2;
    }

    int sift_up(int i){
        if (a[parent(i)] >= a[i] || i <= 0){
            return i;
        }
        if (a[i] > a[parent(i)]) {
            swap(a[i], a[parent(i)]);
        }
        return sift_up(parent(i));
    }

    void insert(int value){
        a.push_back(value);
        int last_inserted_value_index = a.size() - 1;
        sift_up(last_inserted_value_index);
    } 

    int increase_key(int i, int dx){
        a[i] = a[i] + dx;
        return sift_up(i);
    }

    void print(){
        for (auto i: a) cout << i << " ";
        cout << endl;
    }

};

int main() {
    Max_Heap *heap = new Max_Heap();

    int n; cin >> n;

    for (int i = 0; i < n; i++){ 
        int x; cin >> x;
        heap->insert(x);
    }
    
    int m; cin >> m;

    for (int i = 0; i < m; i++){
        int index, x;
        cin >> index >> x;
        cout << heap->increase_key(index - 1, x) + 1 << endl;;
    }
    heap->print();
    return 0;
}