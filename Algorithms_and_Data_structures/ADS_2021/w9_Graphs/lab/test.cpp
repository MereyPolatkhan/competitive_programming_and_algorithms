#include <iostream>
#include <queue>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int n, i, j, k, f, s;
    cin >> n;
    queue<int> q;
    
    int a[n][n], d[n];
    int c[n];
    
    for (i = 0; i < n; ++i) {
        d[i] = 1000000000;
        for (j = 0; j < n; ++j) 
            cin >> a[i][j];
    }

    cin >> s >> f; 
    s--; f--;
    
    d[s] = 0; 
    q.push(s);
    
    while(q.empty() == false){
        i = q.front();
        q.pop();
        for (j = 0; j < n; ++j)
            if (a[i][j] == 1 && d[j] > d[i] + 1) {
                d[j] = d[i] + 1;
                q.push(j);
                c[j] = i;
            }
    }
    cout << "d[f]: \n";
    if (d[f] < 1000000000) 
        cout << d[f] << endl;
    
    cout << "d[i]: \n";
    for (int i = 0; i < n; i++) {
        cout << i << " -- "<< d[i] << "\n";
    }
    cout << endl;

    cout << "c[i]: \n";
    for (int i = 0; i < n; i++) {
        cout << i << " -- "<< c[i] << "\n";
    }

    
    return 0;
}
