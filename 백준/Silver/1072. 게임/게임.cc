#include<iostream>
using namespace std;
int main() {
	long long int X, Y, Z, count = 0;
	cin >> X >> Y;
	Z = (Y * 100) / X;
	int f = 0, e = X;
	int mid, res = 0;
	if (Z == 100 || Z == 99) {
		cout << -1;
		return 0;
	}
	while (f <= e) {
		mid = (f + e) / 2;
		if ((((Y + mid)) * 100) / (X + mid) != Z){
			res = mid;
			e = mid - 1;
		}
		else {
			f = mid + 1;
		}
	}
	cout << res << "\n";
}