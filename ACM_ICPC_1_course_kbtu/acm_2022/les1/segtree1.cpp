#include <iostream> 
#include <vector> 
using namespace std; 
 
const int size = 1e6; 
int t[size*4]; 
 
void build(vector<int> &v, int left_side, int right_side, int tree_index=1) { 
    if (left_side > right_side) { 
        return; 
    } 
    if(left_side == right_side) { 
        t[tree_index] = v[left_side]; 
        return; 
    } 
    int middle = (left_side + right_side) / 2; 
    build(v, left_side, middle, tree_index * 2); 
    build(v, middle+1, right_side, tree_index * 2 + 1); 
    t[tree_index] = min(t[tree_index * 2], t[tree_index * 2 + 1]); 
} 
 
void build(vector<int> &v) { 
    build(v, 0, v.size()-1); 
} 
 
// 1 2 3  4 5 6 7  8 9 
// 2 5 1 [5 6 1 7] 0 4 
 
 
 
int get_min(int l, int r, int left_side, int right_side, int tree_index=1) { 
    if(left_side > r || right_side < l) { 
        return 1e9; 
    } 
    if(l <= left_side && right_side <= r) { 
        return t[tree_index]; 
    } 
    int middle = (left_side + right_side) / 2; 
    int ans = min( 
        get_min(l, r, left_side, middle, tree_index * 2), 
        get_min(l, r, middle+1, right_side, tree_index * 2 + 1) 
    ); 
    return ans; 
} 
 
 
 
 
 
 
void change_element(int index, int value, int left_side, int right_side, int tree_index=1) { 
    if (left_side > right_side) { 
        return; 
    } 
    if (left_side > index || right_side < index) { 
        return; 
    } 
    if (left_side == right_side) { 
        t[tree_index] = value; 
    } 
    int middle = (left_side + right_side) / 2; 
    change_element(index, value, left_side, middle, tree_index * 2); 
    change_element(index, value, middle + 1, right_side, tree_index * 2 + 1); 
    t[tree_index] = min(t[tree_index * 2], t[tree_index * 2 + 1]); 
} 
 
void print_t(vector<int> &v){ 
    for(int i = 0; i < v.size()*2; i++) { 
        cout << t[i] << ' '; 
    } 
    cout << endl; 
} 
 
 
 
 
 
int main() { 
    vector<int> v = {2, 5, 1, 5, 6, 1, 7, 0, 4}; 
    build(v); 
    print_t(v); 
    cout << get_min(6, 6, 0, v.size()-1) << endl; 
 
}