#include <iostream>
using namespace std;

struct stack {
  // [0, n)
  char a[(int)1e6];
  int n;

  stack() {
    n = 0;
  }

  int size() {
    return n;
  }

  void push(char x) {
    a[n] = x;
    n++;
  }

  void pop() {
    if (n == 0) {
      cerr << "Stack error: pop of empty stack\n";
            exit(0);
    }
    n--;
  }

  char top() {
    return a[n-1];
  }
};

int main() {

  stack st1, st2;
    string s1,s2;
  cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++){
        if (s1[i] !='#'){
            // cout << s1[i] << " ";
            st1.push(s1[i]);
        } 
        else {

        }
    }

  for (int i = 0; i < s2.size(); i++){
        if (s2[i] !='#'){
            st2.push(s2[i]);
        }
    }
    int cnt=0;
    for (int i=0; i < st1.size(); i++){
        if(st1.top() == st2.top()){
        cnt++;
        // st1.pop();
        // st2.pop();
        }
        }
    cout << cnt <<endl;
    cout << st1.size()<< endl;
    cout << st2.size() << endl;
    if ( st1.size() == cnt and st2.size() == cnt )
    cout << "YES\n";
    else
    cout << "NO\n"; 
  
    while (st1.size()>0){
        cout << "st1:"<< st1.top() << endl;
        st1.pop();
    }
    while (st2.size()>0){
        cout << "st2:" <<  st2.top() << endl;
        st2.pop();
    }

    return 0;
}