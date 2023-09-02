#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}

vector<int> p_f(string s) { // O(n)
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[i] == s[j]) 
            j = j + 1;
        p[i] = j;
    }
    return p;
}




ll cnt = 0;


bool contains(string s, string t) {
    string q = t + '$' + s;

    vector<int> p = p_f(q);

    for (int i = 0; i < q.size(); i++) {
        if (p[i] == t.size()) {
            return true;
        }
    }

    return false;
}

void func(string t, int j, string s) {
    
    string st = "";

    for (int i = t.size(); i <= j - t.size(); i++) {
        st += s[i];
    }


    string n = "";
    for (int i = j + 1; i <= s.size() - 1 - t.size(); i++) {
        n += s[i];
    }

    if (st.size() == 0 or n.size() == 0) {
        return;
    }

    // cout << "a: " << t << "  st : " << st << "  n: " << n << "\n";
    

    bool flag = contains(st, n);

    if (flag) {
        cnt += (st.size() - 2);
    } 
    else {
        cnt += (st.size() - 1);
    }

}

void kmp(string s, string t) {
    string q = t + '$' + s;

    vector<int> p = p_f(q);


    vector<int> a;

    for (int i = t.size() + 1; i < q.size(); i++) {
        a.pb(p[i]);
    }


    // cout << "t : " << t << " a: "; print(a);

    if (a[t.size() - 1] != a[a.size() - 1]) {
        return;
    }




    for (int i = t.size() + 2; i <= a.size() - 1 - t.size() - 1; i++) {
        if (a[i] == t.size()) {
            func(t, i, s);
        }
    }

}



void find(string s) {
    for (int n = 1; n <= s.size() - 5; n++) {
        string t = s.substr(0, n);
        kmp(s, t);
    }
}

void solve() {
    // N = 700
    string s;
    cin >> s;

    // find A with O(n^2)
    // A S T A N A
    // if we cannot find then output 0

    if (s.size() >= 6)
        find(s);

    cout << cnt << "\n";
}


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

