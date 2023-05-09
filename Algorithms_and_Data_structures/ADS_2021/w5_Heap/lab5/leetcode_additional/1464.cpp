#include <bits/stdc++.h> 

using namespace std; 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2){
                max2 = nums[i];
            }
        }        

        return (max1 - 1) * (max2 - 1);
    }
};



class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // n log n
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};


class Solution3 {
public:
    priority_queue <int> pq;

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) { // n 
            pq.push(nums[i]);
        }
        int i = pq.top(); // O(1)
        pq.pop(); // log n
        int j = pq.top(); // O(1)
        return (i - 1) * (j - 1);
    } // O(n + log n)
};

int main() {


    return 0;
}