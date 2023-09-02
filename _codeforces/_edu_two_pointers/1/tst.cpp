#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
    int arr1[m];
    for(int i = 0; i < n ;i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    int  cnt = 0;
    if(n > m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i] == arr1[j]){
                    cnt++;
                }
            }
        }
    }
    else{
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i] == arr1[j]){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;


}