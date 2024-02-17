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

int main() {
    multiset<int> myMultiset = {1, 2, 2, 4, 4, 4, 10};

    int x = 6; // The element you want to compare

    // Use lower_bound to find the first element that is not less than x
    auto it = myMultiset.lower_bound(x);
    cout << "it: " << *it << "\n";
    // Use distance to find the number of elements less than x
    int count = distance(myMultiset.begin(), it);

    cout << "Number of elements less than " << x << ": " << count << endl;

    return 0;
}
