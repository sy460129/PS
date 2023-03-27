#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long* arr = new long long[n];
	long long res = 2147483647;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int f = 0, c = 0, e = n - 1;
	while (1) {
		int mid = (f + e) / 2;
		if (arr[c] + arr[mid] > 0) {
			e = mid - 1;
		}
		else if (arr[c] + arr[mid] < 0) {
			f = mid + 1;
		}
		if (abs(arr[c] + arr[mid]) < res) {
			if (c != mid) {
				res = abs(arr[c] + arr[mid]);
				v.clear();
				v.push_back(arr[c]);
				v.push_back(arr[mid]);
			}
		}
		if (f > e) {
			c++;
			f = 0, e = n - 1;
		}
		if (c == n || res == 0) {
			break;
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << v[1];
}