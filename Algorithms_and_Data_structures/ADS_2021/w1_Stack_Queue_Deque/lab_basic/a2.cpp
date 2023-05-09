#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <int> st;
    string k;
    while(true){
        cin >> k;
        if(k == "push"){
            int x;
            cin >> x;
            st.push(x);
            cout << "ok\n";
        }
        if(k == "pop"){
            if(st.size() > 0){
                cout << st.top() << "\n";
                st.pop();
            }
            else{
                cout << "error\n";
            }
        }
        if(k == "size"){
            cout << st.size() << "\n";
        }
        if(k == "back"){
            if(st.size() > 0){
                cout << st.top() << "\n";
            }
            else{
                cout << "error\n";
            }
        }
        if(k == "clear"){
            while (!st.empty()){
                st.pop();
            }
            cout << "ok\n";
        }
        if(k == "exit"){
            cout << "bye\n";
            return 0;
        }
    }        
}