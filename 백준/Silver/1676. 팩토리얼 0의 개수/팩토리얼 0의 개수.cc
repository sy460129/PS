#include<iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j % 5 == 0) {
			cnt++;
			j /= 5;
		}
	}
	cout << cnt;
}