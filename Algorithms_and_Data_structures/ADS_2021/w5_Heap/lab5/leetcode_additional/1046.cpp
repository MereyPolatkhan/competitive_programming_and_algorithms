#include <bits/stdc++.h> 

using namespace std; 

class Solution {
public:
    priority_queue <int> pq;

    int lastStoneWeight(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        return res(pq);
    }

    int res(priority_queue <int> pq){
        if (pq.size() == 1){
            return pq.top();
        }
        int top_max = pq.top();
        pq.pop();

        int top_max_2 = pq.top();
        pq.pop();

        pq.push(top_max - top_max_2);

        return res(pq);
    }

};

int main() {

    Solution s;
    vector <int> st = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(st);
    return 0;
}
