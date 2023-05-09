#include <bits/stdc++.h> 

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int random(vector<int> & arr, int low, int high) {
    srand(time(NULL));
    int random_num = rand() % (high - low) + low;
    
    swap(arr[random_num], arr[high]);
    return partition(arr, low, high);
}

void quick_sort(vector<int> & arr, int low, int high) {
    if (low < high) {
        int p = random(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void solve() {
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> s1, s2;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            s1.push_back((int)s[i]);
        }
        else {
            s2.push_back((int)s[i]);
        }
    }   

    
    quick_sort(s1, 0, s1.size() - 1);
    quick_sort(s2, 0, s2.size() - 1);

    for (auto i: s1) cout << (char)i;
    for (auto i: s2) cout << (char)i;
}


int main() {

    solve();

    return 0;   
}



