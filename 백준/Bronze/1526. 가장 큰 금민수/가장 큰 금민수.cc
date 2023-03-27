#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int>v;
void str(int x) {
	int a = x;
	bool check = false;
	while (x!=0) {
		int t = x % 10;
		if (t != 4 && t != 7) {
			check = true;
		}
		if (check) {
			break;
		}
		x /= 10;
	}
	if (!check) {
		v.push_back(a);
	}
}
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		str(i);
	}
	cout << v.back();
}