#include<iostream>
#include<vector>
#include<algorithm>
int compare(int a, int b) {
	return a > b;
}
using namespace std;
int main() {
	int n,x;
	vector<int>v;
	cin >> n;
	while (n != 0) {
		x = n % 10;
		n /= 10;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), compare);
	for (auto& e : v) {
		cout << e;
	}
}