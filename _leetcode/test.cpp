#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        long long res = 0;
        
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[index] > nums[i]) {
                index = i;
            }
        }
        
        vector<int> a;
        for (int i = index; i < n; i++) {
            a.push_back(nums[i]);
        }

        for (int i = 0; i < index; i++) {
            a.push_back(nums[i]);
        }

        int j = 0;
        
        for (int i = 0; i < n; i++) {
            // res += min(a[i], (x * i + a[0]));
            if (a[i] < x * (i - j) + a[0]) {
                res += a[i];
            }
            else {
                res += x * (i - j) + a[0];
                j = i;
            }
        }
        return res;      
    }
};




int main() {
  
    string a, b;
    cin >> a >> b;

    Solution s;
    cout << s.addStrings(a, b);


    return 0;
}