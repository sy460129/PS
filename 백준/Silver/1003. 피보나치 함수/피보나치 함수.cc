#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v(41);
	vector<int>vec(41);
	v[0] = 1;
	v[1] = 0;
	vec[0] = 0;
	vec[1] = 1;
	for (int i = 2; i <= 40; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	for (int i = 2; i <= 40; i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	int T, x;
	cin >> T;
	while (T--) {
		cin >> x;
		cout << v[x] << " " << vec[x] << "\n";
	}
}