#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
bool arr[1000];
using namespace std;
int main() {
	int j = 0;
	string s, c;
	vector<char>v;
	getline(cin, s);
	getline(cin, c);
	for (int i = 0; i < c.length(); i++) {
		if (s[j] == c[i]) {
			j++;
		}
		else {
			if (!arr[c[i] - 'a']) {
				cout << c[i];
			}
			arr[c[i] - 'a'] = true;
		}
	}
}