#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dp[1000001];
int main() {
	int n;
	vector<int>v;
	priority_queue<int, vector<int>, greater<int>>q;
	cin >> n;
	int* arr = new int[n];
	v.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			dp[i] = v.size() - 1;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[it] = arr[i];
			dp[i] = it;
		}
	}
	int t = v.size() - 1;
	cout << t << "\n";
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == t) {
			q.push(arr[i]);
			t--;
		}
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
}