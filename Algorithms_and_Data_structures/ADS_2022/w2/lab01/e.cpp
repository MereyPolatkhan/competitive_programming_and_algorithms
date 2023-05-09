#include <iostream>
#include <queue> 

using namespace std;

int main() {

    deque<int> boris;
    deque<int> nursik;

    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        boris.push_back(x);
    }

    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        nursik.push_back(x);
    }
    int k = 0;
    while (true) {
        int bf = boris.front();
        int nf = nursik.front();
        if (boris.size() == 0 || nursik.size() == 0) {
            break;
        }
        if (k >= 1000000) {
            cout << "blin nichya";
            return 0;
        }
        if (bf == 0 && nf == 9) {
            nursik.pop_front();
            boris.pop_front();
            boris.push_back(bf);
            boris.push_back(nf);
        }
        else if (nf == 0 && bf == 9) {
            nursik.pop_front();
            boris.pop_front();
            nursik.push_back(bf);
            nursik.push_back(nf);            
        }
        else if (bf > nf) {
            nursik.pop_front();
            boris.pop_front();
            boris.push_back(bf);
            boris.push_back(nf);
        }
        else if (nf > bf) {
            nursik.pop_front();
            boris.pop_front();
            nursik.push_back(bf);
            nursik.push_back(nf);
        }
        k++;
    }

    if (boris.size() != 0) {
        cout << "Boris";
    }
    else {
        cout << "Nursik";
    }
    cout << " " << k;
    return 0;
}