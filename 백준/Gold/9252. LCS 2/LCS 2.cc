#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LCS[1001][1001];
int main() {
	string s, c;
	cin >> s >> c;
	vector<int>v;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 1; j <= c.length(); j++) {
			if (s[i - 1] == c[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
	int y = s.length();
	int x = c.length();
	while (LCS[y][x] != 0) {
		if (LCS[y][x] == LCS[y][x - 1]) {
			x--;
		}
		else if (LCS[y][x] == LCS[y - 1][x]) {
			y--;
		}
		else if (LCS[y][x] - 1 == LCS[y - 1][x - 1]) {
			v.push_back(y);
			y--;
			x--;
		}
	}
	cout << LCS[s.length()][c.length()] << "\n";
	while (!v.empty()) {
		cout << s[v.back() - 1];
		v.pop_back();
	}
}