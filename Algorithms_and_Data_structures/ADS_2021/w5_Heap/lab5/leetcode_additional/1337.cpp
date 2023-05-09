class Solution {
public:
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> pq;
    vector <int> res;
    int counter1(vector<int>& a) {
        int k = 0;
        for (int i = 0; i < a.size(); i++){
            if (a[i] == 1) {
                k++;
            }
        }
        return k;
    } 

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for (int i = 0; i < mat.size(); i++) {
            pq.push({counter1(mat[i]), i});
        }

        while (k > 0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }

    
};
