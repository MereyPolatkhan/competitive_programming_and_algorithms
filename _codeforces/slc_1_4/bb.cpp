#include <bits/stdc++.h> 
#include <iomanip>
using namespace std; 

bool cmp(pair<string,int> a, pair<string,int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}


bool valid(string v){ 
    int cnt1 = 0, cnt2= 0; 
    for(char c:v){ 
        if(c == '.')cnt1++; 
        if(c == 'X')cnt2++; 
    } 
 
    return cnt1 == 3 and cnt2 == 1; 
} 
 
int ind(string v){ 
    for(int i = 0; i < v.size(); i++){ 
        if(v[i] == 'X')return i; 
    } 
} 
 
 
int main(){ 
 
    freopen("arrange.in", "r", stdin); 
     
    freopen("arrange.out", "w", stdout); 
 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
 
    int n, m; 
    cin >> n >> m; 
    map<string, int> mp; 
    vector<string> names; 
    for(int i = 0; i < n; i++){ 
        string s;cin >> s; 
        names.push_back(s); 
        mp[s] = 0; 
    } 
 
    double inv = 0; 
 
    for(int i = 0; i < m; i++){ 
        string v; 
        cin >> v; 
        if(!valid(v))inv++; 
        else{ 
            mp[names[ind(v)]]++; 
        } 
    } 
 
    double a = (float)100/m; 
 
    vector<pair<string,int>> p; 
    for(auto &it:mp){ 
        p.push_back(it); 
    } 
 
    sort(p.begin(), p.end(), cmp); 
 
    for(auto x: p){ 
        cout << fixed;
        cout << x.first << ' ' << setprecision(2) << double(x.second) * a << "\n"; 
    } 
 
    cout << "Invalid "  << setprecision(2)  << inv*a; 
 
    return 0; 
}