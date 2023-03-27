#include<iostream>
#include<cmath>
using namespace std;
int sm[3][3];
int ma[3][3];
int main() {
	int n, a, b, c, j = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (i == 0) {
			sm[i][0] = a, sm[i][1] = b, sm[i][2] = c;
			ma[i][0] = a, ma[i][1] = b, ma[i][2] = c;
		}
		else {
			if (j == 1 && i == 1) {
				sm[j][0] = min(sm[j - 1][0], sm[j - 1][1]) + a;
				sm[j][1] = min(sm[j - 1][0], min(sm[j - 1][1], sm[j - 1][2])) + b;
				sm[j][2] = min(sm[i - 1][1], sm[j - 1][2]) + c;
				ma[j][0] = max(ma[j - 1][0], ma[j - 1][1]) + a;
				ma[j][1] = max(ma[j - 1][0], max(ma[j - 1][1], ma[j - 1][2])) + b;
				ma[j][2] = max(ma[j - 1][1], ma[j - 1][2]) + c;
			}
			else if (j == 1) {
				sm[j][0] = min(sm[j + 1][0], sm[j + 1][1]) + a;
				sm[j][1] = min(sm[j + 1][0], min(sm[j + 1][1], sm[j + 1][2])) + b;
				sm[j][2] = min(sm[j + 1][1], sm[j + 1][2]) + c;
				ma[j][0] = max(ma[j + 1][0], ma[j + 1][1]) + a;
				ma[j][1] = max(ma[j + 1][0], max(ma[j + 1][1], ma[j + 1][2])) + b;
				ma[j][2] = max(ma[j + 1][1], ma[j + 1][2]) + c;
			}
			else {
				sm[j][0] = min(sm[j - 1][0], sm[j - 1][1]) + a;
				sm[j][1] = min(sm[j - 1][0], min(sm[j - 1][1], sm[j - 1][2])) + b;
				sm[j][2] = min(sm[j - 1][1], sm[j - 1][2]) + c;
				ma[j][0] = max(ma[j - 1][0], ma[j - 1][1]) + a;
				ma[j][1] = max(ma[j - 1][0], max(ma[j - 1][1], ma[j - 1][2])) + b;
				ma[j][2] = max(ma[j - 1][1], ma[j - 1][2]) + c;
			}
		}
		j++;
		if (j > 2) {
			j = 1;
		}
	}
	if (n == 1) {
		cout << max(ma[0][0], max(ma[0][1], ma[0][2])) << " "
			<< min(sm[0][0], min(sm[0][1], sm[0][2]));
		return 0;
	}
	if (j == 2) {
		cout << max(ma[j - 1][0], max(ma[j - 1][1], ma[j - 1][2])) << " "
			<< min(sm[j - 1][0], min(sm[j - 1][1], sm[j - 1][2]));
	}
	else {
		cout << max(ma[j + 1][0], max(ma[j + 1][1], ma[j + 1][2])) << " "
			<< min(sm[j + 1][0], min(sm[j + 1][1], sm[j + 1][2]));
	}
}