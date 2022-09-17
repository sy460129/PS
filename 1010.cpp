#include <iostream>
using namespace std;
int arr[31][31];
int main() {
	int n, a, b;
	cin >> n;
	for(int i=1; i<30; i++){
		for(int j=0; j<=i; j++){
			if(j==0 || j==i){
				arr[i][j]=1;
			}
			else if(j==1){
				arr[i][j]=i;
			}
			else{
				arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
			}
		}
	}
	while(n--){
		cin >> a >> b;
		cout << arr[b][a] << "\n";
	}
}