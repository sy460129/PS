#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll init(vector<ll>& arr, vector <ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}
ll update(vector <ll>& tree, int node, int start, int end, int index, ll diff) {
	if (!(start <= index && index <= end)) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = diff;
	}
	if (start != end) {
		int mid = (start + end) / 2;
		return tree[node] = min(update(tree, node * 2, start, mid, index, diff), update(tree, node * 2 + 1, mid + 1, end, index, diff));
	}
}
ll query(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left>end || right<start) {
		return 2147483647;
	}
	if (start>=left && end<=right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(query(tree, node * 2, start, mid, left, right), query(tree, node * 2 + 1, mid + 1, end, left, right));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll>arr(n);
	vector<ll>tree(tree_size);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, n - 1);
	cin >> m;
	ll a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(tree, 1, 0, n - 1, b - 1, c);
		}
		else {
			cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}