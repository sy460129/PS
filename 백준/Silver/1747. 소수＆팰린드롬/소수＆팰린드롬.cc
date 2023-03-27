#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1004001];
int main() {
	vector<int>v;
	string s, c;
	int n;
	cin >> n;
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < 1004001; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= 1004001 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	for (int i = n; i <= 1004001; i++) {
		if (arr[i] == 0) {
			int cnt = 1;
			s = to_string(i);
			c = s;
			reverse(s.begin(), s.end());
			for (int j = 0; j < s.length(); j++) {
				if (s[j] != c[j]) {
					cnt = 0;
					break;
				}
			}
			if (cnt == 1) {
				cout << i;
				return 0;
			}
		}
	}
}