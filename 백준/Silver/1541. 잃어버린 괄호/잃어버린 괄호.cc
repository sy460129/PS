#include<iostream>
using namespace std;
int arr[51];
int main() {
	int sum = 0, j = 0, te;
	string s, t;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '-' && s[i] != '+') {
			t += s[i];
		}
		else {
			if (s[i] == '+') {
				te= atoi(t.c_str());
				t.clear();
				sum += te;
			}
			else {
				te = atoi(t.c_str());
				t.clear();
				sum += te;
				arr[j] = sum;
				sum = 0;
				j++;
			}
		}
	}
	te = atoi(t.c_str());
	sum += te;
	arr[j] = sum;
	int res = 0;
	for (int i = 1; i <= j; i++) {
		res -= arr[i];
	}
	cout << res + arr[0];
}