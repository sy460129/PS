#include <iostream>
using namespace std;
int main() {
	int n, s, t, p;
	cin >> s >> n;
	if (s >= 5 && s < 10) {
		cout << max(n - 500, 0);
	}
	else if (s >= 10 && s < 15) {
		t = max(n - 500, 0);
		cout << min((n / 10) * 9, t);
	}
	else if (s >= 15 && s < 20) {
		t = max(n - 2000, 0);
		cout << min((n / 10) * 9, t);
	}
	else if (s>=20) {
		p = n - 2000;
		p = max(0, p);
		cout << min(p, (n / 4) * 3);
	}
	else {
		cout << n;
	}
	
}