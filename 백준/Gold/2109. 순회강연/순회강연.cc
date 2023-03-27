#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	int n, p, d, sum = 0;
	cin >> n;
	vector<pair<int,int>>v;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		sum += v[i].second;
		q.push(v[i].second);
		if (q.size() > v[i].first) {
			sum -= q.top();
			q.pop();
		}
	}
	cout << sum;
}