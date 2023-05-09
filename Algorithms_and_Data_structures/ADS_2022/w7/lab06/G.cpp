#include <bits/stdc++.h> 

using namespace std;

bool cmp (pair <string, string >a, pair <string, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int partition(vector< pair <string, string> > & arr, int low, int high) {
    pair <string, string> pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (cmp(arr[j], pivot)) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int random(vector< pair <string, string> > & arr, int low, int high) {
    srand(time(NULL));
    int random_num = rand() % (high - low) + low;
    
    swap(arr[random_num], arr[high]);
    return partition(arr, low, high);
}

void quick_sort(vector< pair <string, string> > & arr, int low, int high) {
    if (low < high) {
        int p = random(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}


int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	vector< pair <string, string> > a;

	for (int i = 0; i < n; i++) {
		string oldn, newn;
		cin >> oldn >> newn;

		bool flag = false;
		for (auto &x: a) {
			if (x.second == oldn) {
				x.second = newn;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			a.push_back({oldn, newn});
		}
	}

	quick_sort(a, 0, a.size() - 1);
	cout << a.size() << "\n";
	for (auto x: a) {
		cout << x.first << " " << x.second << "\n";
	}

	return 0;
}