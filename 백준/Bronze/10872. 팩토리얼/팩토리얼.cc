#include<iostream>
using namespace std;
int arr[13];
int main() {
	int n;
	cin >> n;
	arr[0] = 1;
	for (int i = 1; i < 13; i++) {
		arr[i] = arr[i - 1] * i;
	}
	cout << arr[n];
}