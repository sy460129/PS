#include <iostream>
using namespace std;
int arr[5001];
int main(){
	int n;
	cin >> n;
	if(n%2==0){
		for(int i=0; i<n; i++){
			if(i%2==0){
				cout << n/2-i/2 << " ";
			}
			else{
				cout << n-i/2 << " ";
			}
		}
	}
	else{
		for(int i=1; i<=n; i++){
			if(i%2==0){
				cout << n-i/2 << " ";
			}
			else{
				i==n ? cout << n : cout << n/2-i/2 << " ";
			}
		}
	}

}