#include <iostream> 

using namespace std;


int binary_search_left(int x, int a[], int n){
    int left = -1;
    int right = n;

    while (left + 1 < right){
        int mid = (left + right) / 2;
        if (x <= a[mid]){
            right = mid;
        }
        else{
            left = mid;
        }
    }

    return right;
}

int binary_search_right(int x, int a[], int n){
    int left = -1;
    int right = n;

    while(left + 1 < right){
        int mid = (left + right) / 2;

        if (a[mid] <= x){
            left = mid;
        }
        else{
            right = mid;
        }
    }
 
    return left;
}


int main() {

    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }


    for (int i = 0; i < m; i++){
        cin >> b[i];

        int left_found = binary_search_left(b[i], a, n);
        int right_found = binary_search_right(b[i], a, n);

        if (left_found - 1 == right_found) {
            cout << 0 << endl;
        }
        else {
            cout << left_found + 1 << " ";
            cout << right_found + 1 << endl;
        }
    }


    return 0;
}