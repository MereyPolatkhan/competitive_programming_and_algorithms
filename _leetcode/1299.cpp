#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n);
        a[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            a[i] = max(a[i + 1], arr[i + 1]);
        }
        return a;
    }
};


int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution s;
    vector<int> b = s.replaceElements(a);
    for (int i: b) cout << i << " ";



    return 0;
}