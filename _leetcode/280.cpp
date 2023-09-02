// 280. Wiggle Sort Premium
class Solution {
public:
    bool check(int &i, int &j, int n) {
        return 0 <= i and i < n and 0 <= j and j < n;
    }
    void wiggleSort(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        if (n % 2 == 1) {
            n--;
        }

        int i = 1;
        int j = n - 2;

        while (check(i, j, a.size()) and i < j) {
            swap(a[i], a[j]);
            i += 2;
            j -= 2;
        }

        if (a.size() >= 3 and a.size() % 2 == 1) {
            swap(a[a.size() - 1], a[a.size() - 2]);
        }        
    }
};