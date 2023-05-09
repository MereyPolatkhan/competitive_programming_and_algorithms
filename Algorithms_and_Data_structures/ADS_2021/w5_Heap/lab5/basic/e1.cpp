 #include <bits/stdc++.h>

using namespace std;

class MaxHeap{
public:
  vector <int> a;

  int parent(int i){
    return (i-1)/2;
  }
  int left(int i){
    return 2*i + 1;
  }
  int right(int i){
    return 2*i + 2;
  }
  int getSize(){
    return a.size();
  }
  int siftUp(int i){
        if (a[parent(i)] >= a[i] || i <= 0){
            return i;
        }
        if (a[i] > a[parent(i)]) {
            swap(a[i], a[parent(i)]);
        }
        return siftUp(parent(i));
    }
  int siftDown(int i){
    if(left(i) > a.size()-1 || (left(i) < a.size() && right(i) > a.size()-1 && a[i] >= a[left(i)]) || (left(i) < a.size() && right(i) < a.size() && a[i] >= a[left(i)] && a[i] >= a[right(i)]))
      return i;

    int largest = left(i);
    if(right(i) < a.size() && a[largest] < a[right(i)] && a[left(i)] != a[right(i)])
      largest = right(i);

    swap(a[largest], a[i]);
    return siftDown(largest);
  }
  int insert(int val){
    a.push_back(val);
    int ind = a.size()-1;
    return siftUp(ind) + 1;
  }
  pair<int,int> extractMax(){
    int root_val = a[0], res_ind = 0;

    swap(a[0], a[a.size()-1]);
    a.pop_back();

    if(a.size() > 0){
      res_ind = siftDown(0);
      return make_pair(res_ind + 1,root_val);
    }
    return make_pair(0, root_val);
  }

  int deleteKey(int ind){
    int ret_res = a[ind];

    if(ind == a.size() - 1){
      a.pop_back();
      return ret_res;
    }

    swap(a[ind], a[a.size()-1]);
    a.pop_back();

    if(a.size() > 0)
      siftDown(ind);
    return ret_res;
  }

  void print(){
    for(int i=0; i<a.size(); i++)
      cout << a[i] << ' ';
  }
};

int main(){

  MaxHeap* heap = new MaxHeap();

  int n, m, type, val, index;
  cin >> n >> m;
  while(m--){
    cin >> type;

    if(type == 1){
      if(heap->getSize() == 0){
        cout << -1 << '\n';
      }
      else{
        pair <int, int> p = heap->extractMax();
        cout << p.first << ' ' << p.second << '\n';
      }
    }
    else if(type == 2){
      cin >> val;
      if(heap->getSize() >= n){
        cout << -1 << '\n';
      }
      else{
        cout << heap->insert(val) << '\n';
      }
    }
    else{
      cin >> index;
      if(index > heap->getSize() || heap->getSize() == 0 || index == 0){
        cout << -1 << '\n';
      }
      else{
        cout << heap->deleteKey(index-1) << '\n';
      }
    }
  }

  heap->print();

  return 0;
}