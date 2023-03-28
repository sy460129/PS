#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long i = 1, x, cnt = 0;
	vector<int>v;
	v.push_back(0);
	for (int j = 1; j <= 1000000; j++) {
		int k = j;
		while (k % 5 == 0) {
			cnt++;
			k /= 5;
		}
		v.push_back(cnt);
	}
	
	while (1) {
		cin >> x;
		if (x == 0) {
			break;
		}
		else {
			cout << "Case #" << i << ": " << v[x] << "\n";
		}
		i++;
	}
}