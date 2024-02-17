#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;
typedef pair<int, ll> pill;

struct TreapNode
{
    int x, y;
    TreapNode *l, *r;
    TreapNode(int x, int y) : x(x), y(y), l(nullptr), r(nullptr) {}
};
 
void treap_output(TreapNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    treap_output(root->l);
    std::cout << "(" << root->x << ", " << root->y << ") -- ";
    treap_output(root->r);
}
 
TreapNode *treap_merge(TreapNode *t1, TreapNode *t2)
{
    // criteria: x:t1 <= x:t2
    if (t1 == nullptr)
    {
        return t2;
    }
    else if (t2 == nullptr)
    {
        return t1;
    }
 
    if (t1->y >= t2->y)
    {
        t1->r = treap_merge(t1->r, t2);
        return t1;
    }
    else
    {
        t2->l = treap_merge(t1, t2->l);
        return t2;
    }
}
 
void treap_split(TreapNode *t, int x, TreapNode *&l, TreapNode *&r)
{
    if (t == nullptr)
    {
        return;
    }
    if (t->x <= x)
    {
        TreapNode *l_prime = nullptr;
        treap_split(t->r, x, l_prime, r);
 
        l = t;
        l->r = l_prime;
    }
    else
    {
        TreapNode *r_prime = nullptr;
        treap_split(t->l, x, l, r_prime);
 
        r = t;
        r->r = r_prime;
    }
}
 
TreapNode *treap_union(TreapNode *t1, int x, int y = rand())
{
    TreapNode *l = nullptr, *r = nullptr;
 
    treap_split(t1, x, l, r);
    // l -- left side of t1, r -- right side of t2
 
    return treap_merge(treap_merge(l, new TreapNode(x, y)), r);
}


void solve() {
    
}


int main() { 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

