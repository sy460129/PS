#include<iostream>
#include<cmath>
int arr[3];
using namespace std;
int main() {
	int n, t = 0;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '3') {
				arr[0]++;
				break;
			}
			else {
				if (i == s.length() - 1 && s[i] == '4') {
					arr[1]++;
				}
				else if(i == s.length() - 1 && s[i]=='2'){
					arr[2]++;
				}
			}
		}
	}
	while (1) {
		if (arr[0] == 0 || arr[1] == 0) {
			break;
		}
		else {
			arr[0]--;
			arr[1]--;
			t++;
		}
	}
	if (arr[1] != 0) {
		while (1) {
			if (arr[1] == 0 || arr[2] == 0) {
				break;
			}
			else {
				t++;
				arr[2]--;
				if (arr[1] >= 2) {
					arr[1] -= 2;
				}
				else {
					arr[1]--;
				}
			}
		}
	}
	if (arr[0] != 0) {
		t += arr[0];
	}
	if (arr[1] != 0) {
		if (arr[1] % 4 == 0) {
			t += arr[1] / 4;
		}
		else {
			t += arr[1] / 4 + 1;
		}
	}
	else if (arr[2] != 0) {
		if (arr[2] % 2 == 0) {
			t += arr[2] / 2;
		}
		else {
			t += arr[2] / 2 + 1;
		}
	}
	cout << t;
}