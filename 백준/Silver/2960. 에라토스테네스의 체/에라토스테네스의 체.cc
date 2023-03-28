#include<iostream>
using namespace std;
int arr[1001];
int main() {
	int n, x, m = 0;
	cin >> n >> x;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		if(arr[i]==0){
			for (int j = 1; j <= n / i; j++) {
				if (arr[i * j] == 1) {
					continue;
				}
				else {
					arr[i * j] = 1;
					m++;
				}
				if (m == x) {
					cout << i * j;
				}
			}
		}
	}
}
