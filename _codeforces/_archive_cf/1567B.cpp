#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;



int computeXOR(int n)
{  
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}


int const N = (int)3e5 + 7;
int xors[N];
void precalc() {
    for (int i = 1; i < N; i++) {
        xors[i] = xors[i - 1] ^ i;
    }
}

int a, b;
void solve() {
    cin >> a >> b;
    // int x = xors[a - 1];
    int x = computeXOR(a - 1);
    if (x == b) {
        cout << a << "\n";
    }
    else if ((x ^ b) != a) {
        cout << a + 1 << "\n";
    }
    else {
        cout << a + 2 << "\n";
    }
}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precalc();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
