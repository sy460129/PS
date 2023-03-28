#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, cnt = 0, sum = 0;
	cin >> n;
	ll* arr = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			cnt++;
		}
	}
	for (ll i = 0; i < n; i++) {
		if (arr[i] == 0) {
			sum += cnt;
		}
		else {
			cnt--;
		}
	}
	cout << sum;
}