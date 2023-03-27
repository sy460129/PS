#include<iostream>
#include<string>
using namespace std;
string c(string x) {
	int sum = 0;
	for (int i = 0; i < x.length(); i++) {
		sum += x[i] - '0';
	}
	return to_string(sum);
}
int main() {
	string s;
	int cnt = 0;
	cin >> s;
	while (s.length() != 1) {
		s = c(s);
		cnt += 1;
	}
	cout << cnt << "\n";
	if (s =="3" || s== "6" || s=="9") {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}