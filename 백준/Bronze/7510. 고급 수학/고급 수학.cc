#include <iostream>
#include <algorithm>
using namespace std;
int a[3];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		bool c = false;
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) c = true;
		cout << "Scenario #" << i << ":\n";
		c ? cout << "yes\n\n" : cout << "no\n\n";
	}
}
