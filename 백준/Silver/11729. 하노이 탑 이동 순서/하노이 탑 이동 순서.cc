#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
vector<int>t;
void hanoi(int n, int s, int e) {
	if (n <= 0) {
		return;
	}
	hanoi(n - 1, s, 6 - s - e);
	v.push_back(s);
	t.push_back(e);
	hanoi(n - 1, 6 - s - e, e);
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int n;
	cin >> n;
	hanoi(n, 1, 3);
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << t[i] << "\n";
	}
}