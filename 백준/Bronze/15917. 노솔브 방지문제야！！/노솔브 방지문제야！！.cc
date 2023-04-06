#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, i = 0;
	while (1) {
		x = pow(2, i);
		v.push_back(x);
		i++;
		if (i == 31) {
			break;
		}
	}
	cin >> n;
	while (n--) {
		cin >> x;
		find(v.begin(), v.end(), x) != v.end() ? cout << 1 : cout << 0;
		cout << "\n";
	}
}