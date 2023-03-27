#include<iostream>
using namespace std;
int arr[100001];
int main() {
	int n, x;
	cin >> n;
	while (n--) {
		int a = 2;
		cin >> x;
		while (1) {
			if (x % a == 0) {
				arr[a]++;
				x /= a;
			}
			else {
				if (arr[a] != 0) {
					cout << a << " " << arr[a] << "\n";
				}
				arr[a] = 0;
				a++;
				if (x == 1) {
					break;
				}
			}
			
		}
	}
}