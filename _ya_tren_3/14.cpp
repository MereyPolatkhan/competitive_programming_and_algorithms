#include <bits/stdc++.h>

using namespace std;



int main() {

    int n;
    cin >> n;
    
    int begin = 1;

    stack<int> st;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
        // cout << x << " " << begin << "\n";
        while (st.size() > 0 && st.top() == begin) {
            st.pop();
            begin++;
        }
    }   

    if (st.size() == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}