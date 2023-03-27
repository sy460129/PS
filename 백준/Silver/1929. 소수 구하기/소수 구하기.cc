#include<iostream>
using namespace std;
int arr[1000001];
int main() {
	int a, b;
	cin >> a >> b;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= b; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= b / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		if (arr[i] == 0) {
			cout << i << "\n";
		}
	}
}