#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[5000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <5000001; i++) {
		arr[i] = i;
	}
	for (int i = 2; i*i < 5000001; i++) {
		if (arr[i] == i) {
			for (int j = i * i; j < 5000001; j += i) {
				if (arr[j] == j) {
					arr[j] = i;
				}
			}
		}
	}
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		while (x > 1) {
			cout << arr[x] << " ";
			x /= arr[x];
			}
		cout << "\n";
	}
}