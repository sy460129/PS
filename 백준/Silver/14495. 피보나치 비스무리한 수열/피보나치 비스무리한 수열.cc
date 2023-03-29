#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long int>v = { 1,1,1, };
	for (int i = 3; i < 116; i++) {
		v.push_back(v[i - 1] + v[i - 3]);
	}
	int n;
	cin >> n;
	cout << v[n - 1];
}