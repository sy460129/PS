#include<iostream>
#include<vector>
using namespace std;
int arr[10000001];
int main() {
	arr[0] = 1;
	arr[1] = 1;
	vector<int>v;
	for (int i = 2; i < 10000001; i++) {
		if (arr[i] == 0) {
			v.push_back(i);
			for (int j = 2; j < 10000001 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	int n;
	cin >> n;
	cout << v[n-1];
}