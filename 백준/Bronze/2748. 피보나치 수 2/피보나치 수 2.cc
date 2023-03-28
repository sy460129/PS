#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long>v = { 0,1,1 };
	int N;
	long long x;
	for (int i = 3; i <= 90; i++) {
		x = v[i-1] + v[i - 2];
		v.push_back(x);
	}
	cin >> N;
	cout << v[N];
}