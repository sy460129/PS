#include <iostream>
using namespace std;
int arr[101][101];
int brr[101][101];
int crr[101][101];
int main() {
	int n, m, x, y;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	cin >> m >> y;
	for(int i=0; i<m; i++){
		for(int j=0; j<y; j++){
			cin >> brr[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int l=0; l<y; l++){
				crr[i][l]+=arr[i][j] * brr[j][l];
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<y; j++){
			cout << crr[i][j] << " ";
		}
		cout << "\n";
	}
}