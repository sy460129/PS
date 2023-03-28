#include <iostream>
using namespace std;
int arr[10];
bool check[10];
int main(){
	int ans = 0;
	for (int i = 0; i < 9; i++) cin >> arr[i], ans += arr[i];
	for (int i = 0; i < 8; i++) {
		ans -= arr[i];
		check[i] = true;
		for (int j = i + 1; j < 9; j++) {
			ans -= arr[j];
			check[j] = true;
			if (ans == 100) {
				for (int i = 0; i < 9; i++) {
					if (!check[i]) cout << arr[i] << "\n";
				}
				return 0;
			}
			ans += arr[j];
			check[j] = false;
		}
		ans += arr[i];
		check[i] = false;
	}
}