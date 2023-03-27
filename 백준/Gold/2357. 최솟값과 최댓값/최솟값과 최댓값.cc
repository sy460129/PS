#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll inits(vector<ll>& arr, vector<ll>& trees, int node, int start, int end) {
	if (start == end) {
		return trees[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return trees[node] = min(inits(arr, trees, node * 2, start, mid), inits(arr, trees, node * 2 + 1, mid + 1, end));
}
ll initl(vector<ll>& arr, vector<ll>& treel, int node, int start, int end) {
	if (start == end) {
		return treel[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return treel[node] = max(initl(arr, treel, node * 2, start, mid), initl(arr, treel, node * 2 + 1, mid + 1, end));
}
ll finds(vector<ll>& trees, int node, int start, int end, int left, int right) {
	if (left>end || start>right) {
		return 1000000000;
	}
	if (left <= start && end <= right) {
		return trees[node];
	}
	int mid = (start + end) / 2;
	return min(finds(trees, node * 2, start, mid, left, right), finds(trees, node * 2 + 1, mid + 1, end, left, right));
}
ll findl(vector<ll>& treel, int node, int start, int end, int left, int right) {
	if (left>end || start>right) {
		return -1;
	}
	if (left <= start && end <= right) {
		return treel[node];
	}
	int mid = (start + end) / 2;
	return max(findl(treel, node * 2, start, mid, left, right), findl(treel, node * 2 + 1, mid + 1, end, left, right));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	vector<ll>arr(n);
	int h = (int)ceil(log2(n));
	int t = (1 << (1 + h));
	vector<ll>trees(t);
	vector<ll>treel(t);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	inits(arr, trees, 1, 0, n - 1);
	initl(arr, treel, 1, 0, n - 1);
	while (m--) {
		cin >> a >> b;
		cout << finds(trees, 1, 0, n - 1, a - 1, b - 1) << " " << findl(treel, 1, 0, n - 1, a - 1, b - 1) << "\n";
	}
}