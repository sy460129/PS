#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n, x, j = 1, cnt = 0;
	cin >> n;
	stack<int>s;
	vector<string>v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		while (j <= x) {
			s.push(j);
			j++;
			v.push_back("+");
		}
		if (s.top() == x) {
			v.push_back("-");
			s.pop();
		}
		else {
			cnt = 1;
		}
	}
	if (cnt == 0) {
		for (auto& e : v) {
			cout << e << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
}