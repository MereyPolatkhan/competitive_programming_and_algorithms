#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef unsigned long long ull;
 
 
 
int main() {
 
    ull n, k;
    cin >> n >> k;
 
    vector<ull> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    ull l = 0;
    ull cnt = 0;
 
    multiset<ull> st;
 
    for (int r = 0; r < n; r++) {
        st.insert(a[r]);
        while (st.size() > 0 and (*st.rbegin() - *st.begin()) > k) {
            st.erase(st.find(a[l]));
            l++;
        }
        cnt += (r - l + 1);
    }
 
    cout << cnt;
 
 
 
    return 0;
}
