#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[26];
int cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		int t = s.length();
		for (int i = 0; i < t; i++) {
			arr[s[i]-65] += pow(10, t - i - 1);
		}
	}
	sort(arr, arr + 26, cmp);
	int res = 0, c = 9;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) {
			cout << res << "\n";
			return 0;
		}
		else {
			res += arr[i] * c;
			c--;
		}
	}
}