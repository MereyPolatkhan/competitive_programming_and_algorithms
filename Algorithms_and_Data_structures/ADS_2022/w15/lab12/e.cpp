// #include <bits/stdc++.h>

// using namespace std;

// class Edge {
//     public:
//     int a, b, w;
// }

// int n;
// int a[1000][1000];
// int const BIG = 100000;
// vector<Edge> edges;

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> a[i][j];
//         }
//     }

//     Edge e;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (a[i][j] != BIG) {
//                 e.a = i;
//                 e.b = j;
//                 e.w = a[i][j];

//                 edges.push_back(e);
//             }
//         }
//     }

//     vector<int> d(n);
//     vector<int> p(n, -1);


//     for (int i = 0; i < n; i++) {
//         int x = -1e7;
//         for (Edge e: edges) {
//             if (d[e.a] + e.w < d[e.b]) {
//                 d[e.b] = d[e.a] + e.w;
//                 p[e.b] = e.a;
//                 x = e.b;
//             }
//         }
//     }

//     if (x == -1e7) {
//         cout << "NO";
//         return 0;
//     }

//     for (int i = 0; i < n; i++) {
//         int x = p[x];
//     }

//     vector<int> clc;
//     for (int v = x;;v=p[v]) {
//         clc.push_back(v);
//         if (v == x && clc.size() > 1) break;
//     }
//     reverse(clc.begin(), clc.end());

//     cout << "YES" << "\n";
//     if (clc.size() == 0) {
//         return 0;
//     }
//     cout << clc.size() << "\n";
//     for (auto i: clc) cout << i + 1 << " ";

//     return 0;
// }