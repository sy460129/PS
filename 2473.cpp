#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long res = 3333333333, sum;
	vector<int>v;
	long long* arr = new long long[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int c = 0;
	for (int i = 0; i < n - 2; i++) {
		int f = i + 1;
		int e = n - 1;
		while (f < e) {
			sum = arr[i] + arr[f] + arr[e];
			if (sum == 0) {
				cout << arr[i] << " " << arr[f] << " " << arr[e];
				return 0;
			}
			if (abs(sum) < res) {
				res = abs(sum);
				v.clear();
				v.push_back(arr[i]);
				v.push_back(arr[f]);
				v.push_back(arr[e]);
			}
			if (sum < 0) {
				f++;
			}
			else {
				e--;
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto& e : v) {
		cout << e << " ";
	}
}