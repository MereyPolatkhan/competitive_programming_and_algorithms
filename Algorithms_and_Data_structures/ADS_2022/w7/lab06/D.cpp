#include <bits/stdc++.h> 

using namespace std;

bool cmp(pair < pair<int, int>, int > a, pair < pair<int, int>, int > b) {
    if (a.second == b.second) {

        if (a.first.second == b.first.second) {
            return a.first.first < b.first.first;
        }

        return a.first.second < b.first.second;
    }

    return a.second < b.second;
}

int partition(vector< pair < pair<int, int>, int > >& a, int l, int r) {
    pair < pair<int, int>, int > pi = a[r];
    int i = l;

    for (int j = l; j < r; j++) {
        if (cmp(a[j], pi)) {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}


int part_random(vector< pair < pair<int, int>, int > >& a, int l, int r) {
    srand(time(NULL));
    int p = rand() % (r - l) + l;
    swap(a[p], a[r]);

    return partition(a, l, r);
}

void quick_sort(vector< pair < pair<int, int>, int > >& a, int l, int r) {
    if (l < r) {
        int p = part_random(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}


int main() {
    int n;
    cin >> n;

    vector< pair < pair<int, int>, int > > a; 


    for (int i = 0; i < n; i++) {
        int d, m, y;
        char c1, c2;
        cin >> d >> c1 >> m >> c2 >> y;
        
        a.push_back({{d, m}, y});
    }

    quick_sort(a, 0, a.size() - 1);


    for (auto i: a) {
        if (i.first.first < 10) {
            cout << 0;
        }
        cout << i.first.first << "-";
        
        if (i.first.second < 10) {
            cout << 0;
        }
        cout << i.first.second << "-";
          
        cout << i.second << "\n";
    }

    return 0;
}