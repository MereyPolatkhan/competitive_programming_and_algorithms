#include <bits/stdc++.h> 

using namespace std;

class Max_Heap {
public:
    vector<int> a;
    stack<int> st_container;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i){
        return 2 * i + 1;
    }

    int right(int i){ 
        return 2 * i + 2;
    }

    void insert(int value){
        a.push_back(value);
    }

    void Build_Heap_from_array() { // (n/2-1) * logn
        int startIdx = (a.size() / 2) - 1;
        for (int j = startIdx; j >= 0; j--){
            sift_down(j);
        }
    } 


    void sift_down(int i){ // log n
        if (left(i) > a.size() - 1 || 
        (left(i) < a.size() && right(i) > a.size() - 1 && a[i] >= a[left(i)]) || 
        (left(i) < a.size() && right(i) < a.size() && a[i] >= a[left(i)] && a[i] >= a[right(i)])){
            // cout << i + 1 << " ";
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



    void print(){
        for (auto i: a) cout << i << " ";
        cout << endl;
    }

    int size(){
        return a.size();
    }

    void delete_and_add_to_stack(){
        st_container.push(a[0]);
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            sift_down(0);
    }

    void print_stack(){
        while(st_container.size() != 0){
            cout << st_container.top() << " ";
            st_container.pop();
        }
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

    for (int i = 0; i < n; i++){     
        heap->Build_Heap_from_array();
        heap->print();
        heap->delete_and_add_to_stack();
    }
    heap->print_stack();
    return 0;
}