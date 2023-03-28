#include<iostream>
#include<string>
using namespace std;
int main() {
	int A, B, C, max, mid, min;
	string s;
	cin >> A >> B >> C;
	cin >> s;
	if (A > B) {
		if (A > C) {
			max = A;
			if (B > C) {
				mid = B;
				min = C;
			}
			else {
				mid = C;
				min = B;
			}
		}
		else {
			max = C;
			mid = A;
			min = B;
		}
	}
	else {
		if (B > C) {
			max = B;
			if (A > C) {
				mid = A;
				min = C;
			}
			else {
				mid = C;
				min = A;
			}
		}
		else {
			max = C;
			mid = B;
			min = A;
		}
	}
	A = min;
	B = mid;
	C = max;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'A') {
			cout << A << " ";
		}
		else if (s[i] == 'B') {
			cout << B << " ";
		}
		else {
			cout << C << " ";
		}
	}
}