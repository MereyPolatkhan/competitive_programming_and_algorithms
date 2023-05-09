#include <iostream>
#include <vector>

using namespace std;

vector<string> rows;

bool firstIsSmaller(string a, string b) {
    if(a.size() == b.size()) return true;
    else return a.size()<b.size();
}

void merge(int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    vector<string> leftArray(subArrayOne);
    vector<string> rightArray(subArrayTwo);
    
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = rows[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = rows[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (firstIsSmaller(leftArray[indexOfSubArrayOne],(rightArray[indexOfSubArrayTwo]))) {
            rows[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            rows[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        rows[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        rows[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    leftArray.clear();
    rightArray.clear();
}

void mergeSort(int const begin, int const end) {
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

int main() {
    int n;
    cin>>n;
    string b;getline(cin,b);
    while(n--) { 
        string s;
        getline(cin,s);
        string ns = "";
        for(int i = 0;i < s.size();i++) {
            if(s[i] != ' ') ns+=s[i];
            else if(s[i] == ' ') {
                rows.push_back(ns);   
                ns = "";
            }
        }
        rows.push_back(ns);
        mergeSort(0, rows.size() - 1);
        for(auto i: rows) cout<<i<<" ";
        cout << '\n';
        rows.clear();
    }
}