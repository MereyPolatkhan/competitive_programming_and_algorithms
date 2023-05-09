#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i] - k)) {
                cnt += mp[nums[i] - k];
            }
            mp[nums[i]]++;
        }
        return cnt;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    Solution s; 
    cout << s.subarraySum(a, k);

    return 0;
}