#include <iostream>
using namespace std;
int arr[26];
int circle[101];
int main() {
	int n, m, t, ans = 0, cnt = 0;
	string s, c;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		arr[s[i] - 'a']++;
		circle[i] = s[i] - 'a';
	}
	t = n - 1;
	cin >> m >> c;
	for (int i = 0; i < m; i++) {
		if (arr[c[i]-'a'] == 0) {
			cout << -1;
			return 0;
		}
		while (1) {
			if (c[i]-'a' == circle[t] && cnt!=0) {
				ans += cnt;
				cnt = 0;
				break;
			}
			else {
				cnt++;
				t++;
				if (t == n) t = 0;
			}
		}
	}
	cout << ans;
}