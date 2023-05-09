#include <bits/stdc++.h>

using namespace std;

struct myQueue{
  int a[100000];
  int start, end;

  myQueue(){
    start = 0;
    end = 0;
  }

  void push(int x){
    a[end] = x;
    end++;
  }
  void push_center(int x){
    int center_pos, size = end - start;
    if(size%2==0)
      center_pos = size/2 + start;
    else
      center_pos = size/2 + start + 1;

    for(int i=end-1; i>=center_pos; i--){
      a[i+1] = a[i];
    }
    a[center_pos] = x;
    end++;
    
  }
  void front(){
    if(!empty())
      cout << a[start] << '\n';
  }
  void pop(){
    start++;
  }
  bool empty(){
    return (start==end);
  }

};

int main(){

  myQueue q;

  int n;
  cin >> n;
  
  char c;
  for(int i=0; i<n; i++){
    cin >> c;

    if(c=='+'){
      int x;
      cin >> x;
      q.push(x);
    }  
    else if(c=='*'){
      int x;
      cin >> x;
      q.push_center(x);
    }
    else{
      q.front();
      q.pop();
    }

  }

  return 0;
}