#include <iostream>
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
		swap(arr[x], arr[y]);
	}
	for(int i=1; i<=n; i++){
		cout << arr[i] << " ";
	}
}