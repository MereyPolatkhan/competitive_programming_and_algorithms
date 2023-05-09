#include <bits/stdc++.h> 

using namespace std;


double marks(string s) {
	if (s == "A+") return 4.00;
	if (s == "A") return 3.75;
	if (s == "B+") return 3.50;
	if (s == "B") return 3.00;
	if (s == "C+") return 2.50;
	if (s == "C") return 2.00;
	if (s == "D+") return 1.50;
	if (s == "D") return 1.00;
	if (s == "F") return 0;
}

double gpa(int m) {
	double gc = 0;
	double c = 0;
	
	for (int i = 0; i < m; i++) {
		string mark; int credit;
		cin >> mark >> credit;
		
		gc += marks(mark) * credit;
		c += credit;
	}
	return gc / c;
}

bool cmp (pair<string, double> a, pair<string, double> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int partition(vector<pair<string, double> >& arr, int low, int high) {
    pair<string, double> pivot = arr[high];
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

int random(vector<pair<string, double> > & arr, int low, int high) {
    srand(time(NULL));
    int random_num = rand() % (high - low) + low;
    
    swap(arr[random_num], arr[high]);
    return partition(arr, low, high);
}

void quick_sort(vector<pair<string, double> > & arr, int low, int high) {
    if (low < high) {
        int p = random(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}


int main() {

    int n;
    cin >> n;

	vector<pair<string, double> > a;

    for (int i = 0; i < n; i++) {
        string ln, fn;
        cin >> ln >> fn;

        int m;
        cin >> m;
		
		double g = gpa(m);
		
		a.push_back({ln + " " + fn, g});
    }
	
	quick_sort(a, 0, a.size() - 1);

	for (int i = 0; i < n; i++) {
		cout << fixed;
		cout << a[i].first << " " << setprecision(3) << a[i].second << '\n';
	}
	
    return 0;
}
