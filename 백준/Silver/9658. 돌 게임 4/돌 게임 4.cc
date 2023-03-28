#include<iostream>
using namespace std;
int x[1001];
int main() {
	x[1] = 0;
	x[2] = 1;
	x[3] = 0;
	x[4] = 1;
	for (int i = 5; i <= 1000; i++) {
		if (x[i - 1] == 1 && x[i - 3] == 1 && x[i - 4] == 1) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
		}
	}
	int n;
	cin >> n;
	if (x[n] == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}