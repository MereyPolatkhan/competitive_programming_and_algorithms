#include <bits/stdc++.h> 

using namespace std;

int main() {

    int n;
    cin >> n;
    
    string s;
    cin >> s;

    deque<int> sak;
    deque<int> kat;

    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') sak.push_back(i);
        else if (s[i] == 'K') kat.push_back(i);
    }

    while (sak.size() > 0 && kat.size() > 0){
        if (sak.front() < kat.front()) {
            int newIndex = 1 + max(sak.back(), kat.back());
            sak.pop_front();
            sak.push_back(newIndex);
            kat.pop_front();
        }
        else {
            int newIndex = 1 + max(sak.back(), kat.back());
            kat.pop_front();
            kat.push_back(newIndex);
            sak.pop_front(); 
        }
    }

    if (sak.empty()) {
        cout << "KATSURAGI";
    } 
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}