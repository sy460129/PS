#include<iostream>
using namespace std;
unsigned long long int arr[68];
int main() {
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 68; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
	}
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		cout << arr[x] << "\n";
	}
}