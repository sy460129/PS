#include<iostream>
using namespace std;
long long int arr[101] = { 1,1,1,2,2, };
int main() {
	int n, x;
	for (int i = 5; i < 101; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	cin >> n;
	while (n--) {
		cin >> x;
		cout << arr[x - 1] << "\n";
	}
}