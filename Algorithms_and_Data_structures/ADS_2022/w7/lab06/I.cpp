#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int partition(char a[], int l, int  h) {
	int i = l;
	char piv = a[h];
	
	for (int j = l; j < h; j++) {
		if (a[j] < piv) {
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[i], a[h]);
	return i;
}

int randomize(char a[], int l, int h) {
	srand(time(NULL));
	int rd = rand() % (h - l) + l;
	swap(a[rd], a[h]);
	return partition(a, l, h);
}


void qs(char a[], int l, int h) {
	if (l < h) {
		int p = randomize(a, l, h);
		qs(a, l, p - 1);
		qs(a, p + 1, h);
	}
}


string sort_string(string s) {
	int n = s.size();
	char a[n];
	
	for (int i = 0; i < n; i++) {
		a[i] = s[i];
	}
	
	qs(a, 0, n - 1);
	
	s = "";
	for (int i = 0; i < n; i++) {
		s += a[i];
	}	

	return s;
}


int main() {

    string s;
    cin >> s;

    s = sort_string(s);
    
    cout << s;

    return 0;
}
