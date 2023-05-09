#include <bits/stdc++.h>



using namespace std;


vector<long long> p(1100000, 0);
vector<bool> used(1100000, false);

int main() {

    long long n; long long k;
    cin >> n >> k;

    long long cur = n;
    for (int i = 1; i <= n; i++) {
        if (k >= n - i){
            used[cur] = true;
            p[i] = cur;
            cur--;
            k -= (n - i);
        }
        else {
            if (k == 0) {
                int index = i;
                for (int j = 1; j <= n; j++) {
                    if (used[j] == false) {
                        p[index] = j;
                        index++;
                    }
                }
            }
            else {
                cur = k + 1;
                p[i] = cur;
                used[cur] = true;
                int index = i + 1;
                for (int j = 1; j <= n; j++) {
                    if (used[j] == false) {
                        p[index] = j;
                        index++;
                    }
                }
            }   
            break;
        }
    }



    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }



    return 0;
}