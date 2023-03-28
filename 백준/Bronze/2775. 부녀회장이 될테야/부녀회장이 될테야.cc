#include <iostream>
using namespace std;
int arr[15][15];
int main() {
	int n, a, b;
	for(int i=0; i<=14; i++){
		for(int j=1; j<=14; j++){
			if(i==0){
				arr[i][j]=j;
			}
			else{
				arr[i][j]=arr[i-1][j]+arr[i][j-1];
			}
		}
	}
	cin >> n;
	while(n--){
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
}