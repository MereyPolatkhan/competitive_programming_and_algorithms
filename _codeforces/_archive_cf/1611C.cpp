
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


bool check(deque<int> d, vector<int> &a) {
    deque<int> deq;
    while (d.size() > 1) {
        if (d.front() > d.back()) {
            deq.push_back(d.back());
            d.pop_back();
        }
        else {
            deq.push_front(d.front());   
            d.pop_front();
        }
    }


    if (d.front() == a[0]) {
        deq.push_front(d.front());
    }
    else if (d.front() == a[a.size() - 1]) {
        deq.push_back(d.front());
    }
    else {
        return false;
    }


    
    vector<int> ch;
    for (int &i: deq) ch.push_back(i);

    for (int i = 0; i < ch.size(); i++) {
        if (a[i] != ch[i]) {
            return false;
        }
    }
    return true;
}


void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> d;

    int i = 0; 
    int j = n - 1;

    while (i <= j) {
        if (i == j) {
            d.push_front(a[i]);
            // for (int i : d) cout << i << " ";
            // return;
            if (check(d, a)) {
                for (int &i : d) 
                    cout << i << " ";
                cout << "\n";
                return;
            }
            d.pop_front();
            d.push_back(a[j]);
            if (check(d, a)) {
                for (int &i : d) 
                    cout << i << " ";
                cout << "\n";
                return;
            }
            cout << -1 << "\n";
            return;
        }
        else if (a[i] < a[j]) {
            d.push_front(a[i]);
            i++;
        }
        else {
            d.push_back(a[j]);
            j--;
        }
    }


}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
