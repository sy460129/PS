#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	vector<int>v;
	while (cin >> n) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		v.push_back(-1);
		for (int i = 0; i < n; i++) {
			if (v.back() < arr[i]) {
				v.push_back(arr[i]);
			}
			else {
				auto it = lower_bound(v.begin(), v.end(), arr[i]);
				*it = arr[i];
			}
		}
		cout << v.size() - 1 << "\n";
		v.clear();
	}
}