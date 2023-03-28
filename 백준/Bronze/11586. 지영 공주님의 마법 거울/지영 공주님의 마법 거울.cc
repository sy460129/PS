#include <iostream>
using namespace std;
char arr[101][101];
int main(){
	int n, m;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	cin >> m;
	if(m==1){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	else if(m==2){
		for(int i=0; i<n; i++){
			for(int j=n-1; j>=0; j--){
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	else{
		for(int i=n-1; i>=0; i--){
			for(int j=0; j<n; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
}