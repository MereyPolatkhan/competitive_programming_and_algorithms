#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a.size() <= b.size();
}

void merge(vector<string> & arr, int l, int mid, int r) {
    int n = mid - l + 1;
    int m = r - mid;

    string a[n];
    string b[m];

    for (int i = 0; i < n; i++) {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < m; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n && j < m) {
        if (cmp(a[i], b[j])) {
            arr[k] = a[i];
            k++;
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < n) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < m) {
        arr[k] = b[j];
        j++;
        k++;
    }
}   

void merge_sort(vector<string> & a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
    else {
        return;
    }
}


int main(){

    string ss;
    getline(cin, ss);
    int n = stoi(ss);

    vector<vector<string>> a;
    
    for (int j = 0; j < n; j++) {
        vector<string> t;

        string s;
        getline(cin, s);
        string cur = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                cur += s[i];
            }
            else {
                t.push_back(cur);
                cur = "";
            }
        }    
        t.push_back(cur);
        a.push_back(t);
    }


    // cout << endl;
    for (auto row: a) {
        merge_sort(row, 0, row.size() - 1);
        for (auto i: row) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}