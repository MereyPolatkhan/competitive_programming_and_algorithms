#include <bits/stdc++.h>

using namespace std;

int number, n;
set< vector<int> > res;
vector<int> a(100000, 0);


void gen(vector<int> temp, int j, int cur_sum) {

    if (cur_sum > number) {
        return;
    }
    else if (cur_sum == number) {
        res.insert(temp);
        return;
    }
    else {
        for (int i = j; i <= n; i++) {
            cur_sum += a[i];
            temp.push_back(a[i]);
            gen(temp, i + 1, cur_sum);
            cur_sum -= a[i];
            temp.pop_back();
        }
    }

    
}

void solve() {

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> temp;
    gen(temp, 1, 0);

}

 

int main() {
    // freopen("input.txt", "r", stdin);
    
  
    while (cin >> number >> n) {
        solve();
        cout << "Sums of " << number << ":\n";
        if (res.empty()) {
            cout << "NONE\n";
            continue;
        }
        
        vector<vector<int> > templ;
        for (vector<int> i : res) {
            templ.push_back(i);
        }

        reverse(templ.begin(), templ.end());

        for (auto i : templ) {
            for (int j = 0; j < i.size(); j++) {
                cout << i[j];
                if (j != i.size()-1) cout << "+";
            }
            cout << "\n";
        }

        res.clear();
    }
    


    return 0;
}