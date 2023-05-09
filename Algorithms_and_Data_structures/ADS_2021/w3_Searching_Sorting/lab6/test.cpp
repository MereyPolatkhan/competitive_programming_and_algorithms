#include <bits/stdc++.h> 

using namespace std;



int main() {

    map<char, int> mp;
    set<char> st;

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            st.insert(s[j]);
        }
        for (auto elem: st)
            mp[elem]++;
        st.clear();
    }
    int count = 0;
    for (auto a: mp) {
        if (a.second == n) {
            count ++;
        }
    }
    cout << count;


    return 0;
}