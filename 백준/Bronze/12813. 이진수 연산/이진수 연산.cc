#include<iostream>
using namespace std;
int arr[100001], brr[100001];
int main() {
	string s, c;
	cin >> s >> c;
	int t, x = s.length();
	t = x;
	while (x--) {
		arr[x] = s[x] - '0';
		brr[x] = c[x] - '0';
	}
	for (int i = 0; i < t; i++) {
		cout << (arr[i] & brr[i]);
	}
	cout << "\n";
	for (int i = 0; i < t; i++) {
		cout << (arr[i] | brr[i]);
	}
	cout << "\n";
	for (int i = 0; i < t; i++) {
		cout << (arr[i] ^ brr[i]);
	}
	cout << "\n";
	for (int i = 0; i < t; i++) {
		cout << (!arr[i]);
	}
	cout << "\n";
	for (int i = 0; i < t; i++) {
		cout << (!brr[i]);
	}
}