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

    void sift_down(int i){
        if (left(i) > a.size() - 1 || 
        (left(i) < a.size() && right(i) > a.size() - 1 && a[i] >= a[left(i)]) || 
        (left(i) < a.size() && right(i) < a.size() && a[i] >= a[left(i)] && a[i] >= a[right(i)])){
            cout << i + 1 << " ";
            return;
        }
        int r_or_l = left(i);

        if (right(i) < a.size() && a[right(i)] > a[left(i)]){
            r_or_l = right(i);
        }

        if (a[r_or_l] > a[i]) {
            swap(a[r_or_l], a[i]);
        }
        sift_down(r_or_l);
    }

    int get_max() {
        return a[0];
    }

    int Extract_Max(){
        int max = get_max();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0){
            sift_down(0);
        }
        return max;
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

    for (int i = 0; i < n - 1; i++){
        cout << heap->Extract_Max() << endl;
    }
    return 0;
}