#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
ll arr[300001];
ll t[300001];
int main() {
	ll n, m, x, cnt = 0;
	queue<ll>q;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		t[i] = s.length();
		q.push(t[i]);
	}
	x = q.front();
	q.pop();
	for (int i = 0; i < n; i++) {
		arr[t[i]]++;
		if (i >= m) {
			arr[x]--;
			cnt += arr[x];
			x = q.front();
			q.pop();
		}
	}
	while (!q.empty()) {
		x = q.front();
		arr[x]--;
		cnt += arr[x];
		q.pop();
	}
	cout << cnt;
}