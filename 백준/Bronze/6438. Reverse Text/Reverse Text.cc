#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
}