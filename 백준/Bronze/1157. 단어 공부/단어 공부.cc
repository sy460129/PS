#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int arr[26];
bool cmp(pair<int,char> v1, pair<int,char>v2) {
	return v1.first > v2.first;
}
int main() {
	string s;
	char x = 'A';
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
		arr[s[i] - 'A']++;
	}
	vector<pair<int, char>>v;
	for (int i = 0; i < 26; i++) {
		v.push_back({ arr[i],i + 'A' });
	}
	sort(v.begin(), v.end(), cmp);
	if (v[0].first == v[1].first) {
		cout << "?\n";
		return 0;
	}
	else {
		cout << v[0].second << "\n";
	}
}