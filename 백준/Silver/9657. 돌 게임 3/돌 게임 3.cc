#include<iostream>
using namespace std;
int x[1001];
int main(){
	x[1] = 1;
	x[2] = 0;
	x[3] = 1;
	x[4] = 1;
	for (int i = 5; i <= 1000; i++) {
		if (x[i - 1] == 0 || x[i - 3] == 0 || x[i - 4] == 0) {
			x[i] = 1;
		}
		else {
			x[i] = 0;
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