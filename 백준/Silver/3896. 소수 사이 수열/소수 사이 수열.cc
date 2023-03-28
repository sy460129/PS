#include<iostream>
#include<vector>
using namespace std;
int arr[10000001];
int main() {
	arr[0], arr[1] = 1;
	vector<int>v;
	for (int i = 2; i < 10000001; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j < 10000001 / i; j++) {
				arr[j * i] = 1;
			}
			v.push_back(i);
		}
	}
	int n, x;
	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> x;
		for (int i = 0; i <= 10000001; i++) {
			if (v[i] == x) {
				cout << cnt << "\n";
				break;
			}
			else if (v[i] > x) {
				for (int j = v[i - 1] + 1; j < v[i]; j++) {
					cnt += 1;
				}
				cout << cnt +1 << "\n";
				break;
			}
		}
	}
}