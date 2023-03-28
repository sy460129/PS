#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll arr[10001];
int main() {
	ll n; cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		ans += abs(arr[i + 1] - arr[i]);
	}
	ans += abs(arr[n - 1] - arr[0]);
	cout << ans;
}