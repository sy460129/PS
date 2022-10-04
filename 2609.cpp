#include<iostream>
using namespace std;
int main() {
	int A, B;
	int m = 0, M = 0, max = 0, min = 0;
	cin >> A >> B;
	if (A >= B) {
		while (min <= B) {
			min++;
			if (A % min == 0 && B % min == 0) {
				m = min;
			}
		}
		max = A;
		while (1) {
			if (max % A == 0 && max % B == 0) {
				M = max;
				break;
			}
			max++;
		}
	}
	else {
		while (min <= A) {
			min++;
			if (A % min == 0 && B % min == 0) {
				m = min;
			}
		}
		max = B;
		while (1) {
			if (max % A == 0 && max % B == 0) {
				M = max;
				break;
			}
			max++;
		}
	}
	cout << m << endl << M;
}
