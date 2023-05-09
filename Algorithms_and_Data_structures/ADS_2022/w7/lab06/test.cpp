#include <bits/stdc++.h> 

using namespace std;


int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector <pair<string, string> > v;

    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(v[j].second == s1){
                //don't add
                v[j].second = s2;
                cnt = 1;
                break;
            }
        }
        if(cnt == 0){
            v.push_back(make_pair(s1, s2));
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
}