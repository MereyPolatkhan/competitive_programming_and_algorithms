#include <bits/stdc++.h>

using namespace std;

const int size = 1e6; 
int t[size*4]; 

int counter = 0;
 
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
    if (counter % 2 == 0) t[tree_index] = (t[tree_index * 2] | t[tree_index * 2 + 1]); 
    else t[tree_index] = (t[tree_index * 2] ^ t[tree_index * 2 + 1]);
} 
 
void build(vector<int> &v) { 
    counter = 0;
    build(v, 0, v.size()-1); 
} 

void print_t(vector<int> &v){ 
    for(int i = 0; i < v.size()*2; i++) { 
        cout << t[i] << ' '; 
    } 
    cout << endl; 
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
    if (counter % 2 == 0) t[tree_index] = (t[tree_index * 2] | t[tree_index * 2 + 1]); 
    else t[tree_index] = (t[tree_index * 2] ^ t[tree_index * 2 + 1]);
} 

void change_element(vector<int> & v, int index, int value) {
    counter = 0;
    change_element(index, value, 0, v.size()-1); 
}

int main() {

    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int N = pow(2, n);
    
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    build(v);
    change_element(v, 1, 4);
    print_t(v);   
    
    
    // for (int i = 0; i < m; i++) {
    //     int p, b;
    //     cin >> p >> b;

        
    // }


    return 0;
}