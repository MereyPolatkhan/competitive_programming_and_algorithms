class Solution {
public:
    int numTrees(int n) {
        int a[10000];
        for (int i = 0; i < n; i++){
            a[i] = 1;
        }

        for (int nodes = 2; nodes <= n; nodes++){
            int sum = 0;
            for (int root = 1; root <= nodes; root++){
                int left = root - 1;
                int right = nodes - root; 

                sum = sum + (a[left] * a[right]);
            }
            a[nodes] = sum;
        }

        return a[n];
        
    }
};