#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int>p;
bool cmp(p a, p b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, d, a, b, start = -2147483648, end, cnt = 0, sum = 0;
	vector<p>v;
	priority_queue<int, vector<int>, greater<int>>q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b < a) {
			swap(a, b);
		}
		v.push_back({ a,b });
	}
	cin >> d;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		start = v[i].first;
		end = v[i].second;
		if (end - start <= d) {
			q.push(start);
		}
		while (!q.empty()) {
			if (q.top() < end - d) {
				q.pop();
			}
			else {
				sum = max(sum, (int)q.size());
				break;
			}
		}
	}
	cout << sum << "\n";
}