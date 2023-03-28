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
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
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
	int n, m, a, b;
	cin >> n >> m;
	int h = (int)ceil(log2(n));
	int t = (1 << (1 + h));
	vector<ll>arr(n);
	vector<ll>tree(t);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, n - 1);
	while (m--) {
		cin >> a >> b;
		cout << sum(tree, 1, 0, n - 1, a - 1, b - 1) << "\n";
	}
}