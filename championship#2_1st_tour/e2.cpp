#include<bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 2e5+505;


void solve() {
    int n;
    cin >> n;
    vector<pair<double, double> > p;
    for (int i = 0; i < n; i++){
      int x, y;
      cin >> x >> y;
      p.pb(mp(x,y));
    }
    map<pair<double,double>, int> mp;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        pair<double,double> c;
        c.f = (p[i].f + p[j].f)/2;
        c.s = (p[i].s + p[j].s)/2;
        mp[c]++;
      }
    }
    int mx = -1;
    for (auto m : mp){
      mx = max(mx, m.s);
    }
    cout << n - mx;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}