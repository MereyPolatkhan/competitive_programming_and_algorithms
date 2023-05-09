#include <bits/stdc++.h>


using namespace std;


int main() {

    int t;
    cin >> t;

    unordered_map<string, long long > mp;
    stack<pair<string, long long>> st;

    while (t--) {
        string s;
        cin >> s;
        if (s == "add") {
            long long n; cin >> n;
            string what; cin >> what;
            mp[what] += n;
            if (st.size() > 0 and st.top().first == what) {
                long long temp = st.top().second;
                st.pop();
                st.push({what, temp + n});
            }
            else {
                st.push({what, n});
            }
        }
        else if (s == "get") {
            string what;
            cin >> what;
            cout << mp[what] << "\n";
        }
        else if (s == "delete") {
            long long n;
            cin >> n;
            while (st.size() > 0 and n > 0 and n >= st.top().second) {
                n = n - st.top().second;
                mp[st.top().first] -= st.top().second;
                st.pop();
            }
            if (n > 0 and st.size() > 0) {
                string wh = st.top().first;
                
                mp[wh] -= n;
                if (mp[wh] < 0) mp[wh] = 0;

                long long temp = st.top().second;
                st.pop();


                temp -= n;
                if (temp > 0) st.push({wh, temp});
            }



        }   
    }



    return 0;
}