#include <iostream>
#include <stack> 

using namespace std;


int main() {

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        if (st.size() > 0) {
            while (st.size() > 0 && st.top() > x){
                st.pop();
            }
        }

        if (st.size() == 0) cout << -1 << " ";
        else cout << st.top() << " ";

        st.push(x);
    }

    return 0;
}