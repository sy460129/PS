#include <iostream>
using namespace std;
int arr[101][101];
int main() {
	int n, m, x;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> x;
			cout << arr[i][j] + x << " "; 
		}
		cout << "\n";
	}
}