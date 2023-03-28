#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	vector<int>v;
	cin >> n;
	int* arr = new int[n];
	v.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[it] = arr[i];
		}
	}
	cout << v.size() - 1;
}