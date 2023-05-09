#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int a[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int min_row[n];
    int max_col[m];

    for (int i = 0; i < n; i++){
        min_row[i] = a[i][0];
        for (int j = 0; j < m; j++){
            if (min_row[i] > a[i][j]){
                min_row[i] = a[i][j];
            }
        }
    }


    for (int j = 0; j < m; j++) {
        max_col[j] = a[0][j]; 
        for (int i = 0; i < n; i++) {
            if (max_col[j] < a[i][j]){
                max_col[j] = a[i][j];
            }
        }
    }

    int k = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == min_row[i] && a[i][j] == max_col[j]){
                // cout << a[i][j] << " ";
                k++;
            }
        }
    }

    cout << k;
    
    return 0;
}