#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, x, sum = 0;
	vector<long long>v;
	cin >> n;
	while (n--) {
		cin >> x;
		v.push_back(x);
		sum += x;
	}
	long long res = 0;
	for (int i = 0; i < v.size(); i++) {
		sum -= v[i];
		res += sum * v[i];
	}
	cout << res << "\n";
}