#include<iostream>
#include<set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t, x;
	char c;
	cin >> t;
	while (t--) {
		cin >> n;
		multiset<int>s;
		for (int i = 0; i < n; i++) {
			cin >> c >> x;
			if (c == 'I') {
				s.insert(x);
			}
			else {
				if (x == 1) {
					if (!s.empty()) {
						auto y = s.end();
						y--;
						s.erase(y);
					}
				}
				else if (x == -1) {
					if (!s.empty()) {
						auto y = s.begin();
						s.erase(y);
					}
				}
			}
		}
		if (s.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto k = s.end();
			k--;
			cout << *k << " " << *s.begin() << "\n";
		}
	}
}