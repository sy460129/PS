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
	return tree[node] = (init(arr, tree, node * 2, start, mid) * init(arr, tree, node * 2 + 1, mid + 1, end)) % 1000000007;
}
ll update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (!(start <= index && index <= end)) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = diff;
	}
	int mid = (start + end) / 2;
	return tree[node] = (update(tree, node * 2, start, mid, index, diff) * update(tree, node * 2 + 1, mid + 1, end, index, diff)) % 1000000007;
}
ll mul(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (end<left || start>right) {
		return 1;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return (mul(tree, node * 2, start, mid, left, right) * mul(tree, node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll>arr(n);
	vector<ll>tree(tree_size);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, n - 1);
	ll a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c;
			update(tree, 1, 0, n - 1, b - 1, diff);
		}
		if (a == 2) {
			cout << (mul(tree, 1, 0, n - 1, b - 1, c - 1)) % 1000000007 << "\n";
		}
	}
}