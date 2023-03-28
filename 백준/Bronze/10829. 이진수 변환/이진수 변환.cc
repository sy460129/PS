#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	unsigned long long int n;
	cin >> n;
	string s;
	while (n != 0) {
		s += to_string(n % 2);
		n /= 2;
	}
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
	}
}