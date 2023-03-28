#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s.back() % 2 == 0) {
			cout << "even" << "\n";
		}
		else {
			cout << "odd" << "\n";
		}
	}
}