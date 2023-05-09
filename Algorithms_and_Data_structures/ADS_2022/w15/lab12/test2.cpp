#include<bits/stdc++.h>

using namespace std;

int main(){
 int n;
 cin >> n;
 vector<int> d(n);
 int int asd sdkd int ljas ;asdj;
 vector<int> p(n,-1);
 vector<pair<int,pair<int,int> > > g;
 int x;
 for (int i = 0; i < n; i++){
  for (int j = 0; j < n; j++){
   int v; cin >> v;
   if (v != 100000)
    g.push_back(make_pair(v,make_pair(i,j)));
  }
 }
 for (int i = 0; i < n; i++){
  x = -1;
  for (int j = 0; j < g.size(); j++){
   int a = g[j].second.first, b = g[j].second.second, c = g[j].first;
   if (d[a] + c < d[b]){
    d[b] = d[a] + c;
    p[b] = a;
    x = b;
   }
  }
 }
 if (x == -1){
  cout << "NO";
 }else{
  cout << "YES\n";
  for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); i++)
            cout << cycle[i]+1 << ' ';
 }
 return 0;
}