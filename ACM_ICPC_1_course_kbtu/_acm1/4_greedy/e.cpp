#include <bits/stdc++.h>


using namespace std;

bool cmp(pair< pair<int, int>, pair<int, int> > a, pair< pair<int, int>, pair<int, int> > b){
    if (a.second.first <= b.second.first) {
        if (a.second.second <= b.second.second) {
            return true;
        }
        return false;
    }
    return false;
}


pair<int, int> func(string s) {
    pair<int, int> pr;
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || i == 1) s1 += s[i];
        if (i == 3 || i == 4) s2 += s[i];
    }
    pr.first = stoi(s1);
    pr.second = stoi(s2);
    return pr;
}

int main() {
    int n;
    cin >> n;

    vector<pair< pair<int, int>, pair<int, int> > > a; 

    for (int i = 1; i <= n; i++) {
        string as, bs;
        cin >> as >> bs;
        pair<int, int> aint = func(as);
        pair<int, int> bint = func(bs);
        a.push_back({aint, bint});

    }

    sort(a.begin(), a.end(), cmp);
    
    if (a.size() == 0) {
        cout << 0;
        return 0;
    }
    int cnt = 1;
    int finish_hour = a[0].second.first;
    int finish_minute = a[0].second.second;


    for (int i = 1; i < a.size(); i++) {
        if (finish_hour > a[i].first.first) {
            continue;
        }

        else if (finish_hour == a[i].first.first) {
            if (finish_minute <= a[i].first.second) {
                cnt++;
                finish_hour = a[i].second.first;
                finish_minute = a[i].second.second;
            }
            else continue;
        }

        else if (finish_hour < a[i].first.first) {
            cnt++;
            finish_hour = a[i].second.first;
            finish_minute = a[i].second.second;
        }

    }
    cout << cnt;



    return 0;
}