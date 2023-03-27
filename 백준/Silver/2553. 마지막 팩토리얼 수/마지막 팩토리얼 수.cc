#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>v;
	v.push_back(1);
	for (int i = 1; i <= n; i++) {
		long long j = i;
		j *= v[i - 1];
		while (j % 5 == 0) {
			j /= 10;
		}
		j %= 1000000;
		v.push_back(j);
	}
	cout << v[n] % 10;
}