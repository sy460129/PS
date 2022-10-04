#include<iostream>
#include<string>
using namespace std;
int arr[10];
int main() {
	string s;
	unsigned long long a, b, c;
	cin >> a >> b >> c;
	s = to_string(a * b * c);
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
}