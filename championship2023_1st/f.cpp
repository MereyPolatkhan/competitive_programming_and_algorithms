#include <bits/stdc++.h>

using namespace std;

vector<int> a(3);
int cnt = 0;


int func1(vector<int> a) {
    return a[2] - a[0] + a[2] - a[1];
}   



int func2(vector<int> a) {
    int k = 0;
    while (a[2] - a[1] != 5) {
        a[2]++;
        k++;
    }

    return k + 1 + (a[2] - a[0]) / 5 + (a[2] - a[0]) % 5; 
}

int func3(vector<int> a) {
    int k = 0;
    while (a[2] - a[0] != 5) {
        a[2]++;
        k++;
    }
    return k + 1 + (a[2] - a[1]) / 5 + (a[2] - a[1]) % 5;
}

int main() {    

    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    while (a[2] - a[0] >= 5) {
        int delta = a[2] - a[0];
        int raz = delta / 5;
        cnt += raz;
        a[0] += raz * 5;
    }

    while (a[2] - a[1] >= 5) {
        int delta = a[2] - a[1];
        int raz = delta / 5;
        cnt += raz;
        a[1] += raz * 5;
    }

    // for (int i : a) cout << i << " "; cout << "\n";

    sort(a.begin(), a.end());

    int f1 = func1(a);
    int f2 = func2(a);
    int f3 = func3(a);

    cout << cnt + min(f3, min(f1, f2));

    return 0;
}