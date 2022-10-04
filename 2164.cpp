#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> v;
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push(i);
	}
	while (v.size() != 1) {
		v.pop();
		x = v.front();
		v.push(x);
		v.pop();
	}
	cout << v.front();
}