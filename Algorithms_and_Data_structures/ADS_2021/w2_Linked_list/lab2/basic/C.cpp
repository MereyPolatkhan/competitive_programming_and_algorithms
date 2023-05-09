#include <algorithm> 
#include <iostream>
#include <vector> 
#include <map>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {

    vector<pair<string, int>> v;
    map<string, int> m;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    while(cin >> s) {
        m[s] += 1;
    }

    map<string, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++){
        v.push_back({it->first, it->second});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }


    return 0;
}