#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int>s;
	int n, x, c = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.push(x);
		while (s.top() == c) {
			s.pop();
			c++;
			if (s.empty()) {
				break;
			}
		}
	}
	if (s.empty()) {
		cout << "Nice\n";
	}
	else {
		cout << "Sad\n";
	}
}