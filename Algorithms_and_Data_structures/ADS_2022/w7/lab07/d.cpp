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


bool cmp (pair<double, string> a, pair<double, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void merge(vector<pair<double, string> > & arr, int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    pair<double, string> L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<pair<double, string> > & arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
    else {
        return;
    }
}


int main() {

    int n;
    cin >> n;

	vector<pair<double, string> > a;

    for (int i = 0; i < n; i++) {
        string ln, fn;
        cin >> ln >> fn;

        int m;
        cin >> m;
		
		double g = gpa(m);
		
		a.push_back({g, ln + " " + fn});
    }
	
	merge_sort(a, 0, a.size() - 1);
	
	for (int i = 0; i < n; i++) {
		cout << fixed;
		cout << a[i].second << " " << setprecision(3) << a[i].first << '\n';
	}
	
    return 0;
}
