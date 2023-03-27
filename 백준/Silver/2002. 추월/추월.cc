#include<iostream>
#include<map>
using namespace std;
string arr[1001];
int main() {
	int n, cnt = 0;
	string s;
	cin >> n;
	map<string, int>m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (m[arr[i]] > m[arr[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt << "\n";
}