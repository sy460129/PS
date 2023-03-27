#include <iostream>
using namespace std;
int arr[101][101];
int main(){
	int n, a, b, cnt = 0;
	cin >> n;
	for(int k=0; k<n; k++){
		cin >> a >> b;
		for(int i=a; i<a+10; i++){
			for(int j=b; j<b+10; j++){
				arr[i][j]+=1;
			}
		}
	}
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j]!=1 && arr[i][j]!=0){
				cnt+=arr[i][j]-1;
			}
		}
	}
	cout << 100*n-cnt;
}