#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (!(start <= index && index <= end)) {
		return;
	}
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (right<start || left>end) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int	n, m;
	cin >> n >> m;
	int h = (int)ceil(log2(n));
	int s = (1 << (1 + h));
	vector<ll>arr(n);
	vector<ll>tree(s);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, n - 1);
	ll x, y, a, b;
	while (m--) {
		cin >> x >> y >> a >> b;
		if (x < y) {
			cout << sum(tree, 1, 0, n - 1, x - 1, y - 1) << "\n";
		}
		else {
			cout << sum(tree, 1, 0, n - 1, y - 1, x - 1) << "\n";
		}
		ll di = b - arr[a - 1];
		arr[a - 1] = b;
		update(tree, 1, 0, n - 1, a - 1, di);
	}
}