#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

int ctoi(char c) {
    return (int)c - (int)'a';
}

string s;
int n;

ll func1(vector<int> &cnt) {
    ll res = 0;
    for (int i = 0; i < 26; i++) {
        res = max(res, 1LL * cnt[i]);
        res = max(res, 1LL * cnt[i] * (cnt[i] - 1));
    }

    return res;
}


ll func2(vector<int> &pref, vector<int> &suff) {
    ll res = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) 
                continue;
            res = max(res, 1LL * pref[i] * suff[i]);
        }
    }
    return res;
}

void solve() {
    cin >> s;
    n = s.size();


    vector<vector<int>> suff;
    vector<vector<int>> pref;
    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);

    for (int i = 0; i < n; i++) {
        cnt1[ctoi(s[i])]++;
        pref.pb(cnt1);
    }
    for (int i = n - 1; i >= 0; i--) {
        cnt2[ctoi(s[i])]++;
        suff.pb(cnt2);
    }

    reverse(all(suff));

    ll res = func1(cnt1);
    for (int j = 0; j < n - 1; j++) {
        res = max(res, func2(pref[j], suff[j + 1]));
    }
    cout << res << "\n";
}



ll arr1[26],arr2[26][26];
int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    string S;
    cin>>S;
    for (int i=0;i<S.length();i++){
        int c=S[i]-'a';
        for (int j=0;j<26;j++)
            arr2[j][c]+=arr1[j];
        arr1[c]++;
    }

    // for (int i = 0; i < 26; i++) 
    //     cout << char(i + 'a') << ": " << arr1[i] << "\n";

    // cout << "\n\n";
    
    for (int i = 0; i < 26; i++) {
        cout << char(i + 'a') << ": \n";
        for (int j = 0; j < 26; j++) {
            if (arr2[i][j]) {
                cout << char(j + 'a') << ": " << arr2[i][j] << "\n";
            }
        }
        if (i == 1)return 0;
        cout << "\n\n\n";
    }

    ll ans=0;
    for (int i=0;i<26;i++)
        ans=max(ans,arr1[i]);
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            ans=max(ans,arr2[i][j]);
    cout<<ans<<endl;

    return 0;
}
