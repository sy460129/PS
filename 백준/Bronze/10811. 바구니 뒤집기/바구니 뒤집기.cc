#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int main() {
	int n, m, x, y;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		arr[i] = i;
	}
	while(m--){
		cin >> x >> y;
		reverse(arr + x, arr + y + 1);
	}
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
}