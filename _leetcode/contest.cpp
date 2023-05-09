#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> upper(n, -1);
        vector<int> lower(n, -1);

        for (int i = 0; i < n; i++) {
            if (nums2[i] > nums1[i]) {
                if ((nums2[i] - nums1[i]) % k == 0) {
                    upper[i] = (nums2[i] - nums1[i]) / k;
                }
                else {
                    return -1;
                }
            } 
        } 

        for (int i = 0; i < n; i++) {
            if (nums2[i] < nums1[i]) {
                if ((nums1[i] - nums2[i]) % k == 0) {
                    lower[i] = (nums1[i] - nums2[i]) / k;
                }
                else {
                    return -1;
                }
            } 
            else if (nums2[i] == nums1[i]) {
                lower[i] = 0;
                upper[i] = 0;
            }
        } 
        
        long long s1 = 0, s2 = 0;
        for (auto i: upper) {
            if (i != -1) s1 += i;
        }
        for (auto i: lower) if (i != -1) s2 += i;
        return s1 == s2 ? s1 : -1;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int k;
    cin >> k;

    cout << s.minOperations(a, b, k);
    return 0;   

}