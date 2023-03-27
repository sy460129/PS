#include<iostream>
using namespace std;
int arr[26];
int main() {
	int cnt = 0;
	string s, c;
	cin >> s >> c;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i < c.length(); i++) {
		arr[c[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		cnt += abs(arr[i]);
	}
	cout << cnt << "\n";
}