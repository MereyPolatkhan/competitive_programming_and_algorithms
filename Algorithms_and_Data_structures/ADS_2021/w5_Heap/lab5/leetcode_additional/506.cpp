// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue <pair<int, int>> pq;
        vector <string> results(score.size());

        for (int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        
        for (int i = 0; i < score.size(); i++) {
            if (i == 0) {
                results[pq.top().second] = "Gold Medal";
            }
            else if (i == 1) {
                results[pq.top().second] = "Silver Medal";
            }
            else if (i == 2) {
                results[pq.top().second] = "Bronze Medal";
            }
            else {
                results[pq.top().second] = to_string(i + 1);
            }
            pq.pop();

        }

        return results;
        
    }
};

int main() {
    vector<int> nums{1, 3, 2, 5, 4};
    Solution2 s;
    s.findRelativeRanks(nums);
    
    
    return 0;
}