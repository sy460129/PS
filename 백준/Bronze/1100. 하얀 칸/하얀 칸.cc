#include<iostream>
#include<vector>
using namespace std;
int main() {
	char A[8][8];
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> A[i][j];
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (A[i][j] == 'F') {
						count += 1;
					}
				}
			}
			else {
				if (j % 2 != 0) {
					if (A[i][j] == 'F') {
						count += 1;
					}
				}
			}
		}
	}
	cout << count;
}