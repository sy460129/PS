#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == a[a.size() - i - 1 ]) {
			continue;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}