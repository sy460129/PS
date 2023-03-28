#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		int res = 0, sum = 0;
		if (s[0] == 'O') {
			res = 1;
			sum = 1;
		}
		for (int i = 1; i < s.length(); i++) {
			if (s[i - 1] == 'O' && s[i]=='O') {
				res++;
				sum += res;
			}
			else if (s[i] == 'O') {
				res = 1;
				sum += res;
			}
			else {
				res = 0;
			}
		}
		cout << sum << "\n";
	}
}