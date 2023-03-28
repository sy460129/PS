#include <iostream>
using namespace std;
int arr[6];
int main(){
	int a, m, n;
	for(int i=1; i<=5; i++){
		for(int j=0; j<4; j++){
			cin >> a;
			arr[i]+=a;
		}
		if(i==1)
		{
			m=i, n=arr[i];
		}
		else{
			if(arr[i]>n){
				m=i, n=arr[i];
			}
		}
	}
	cout << m << " " << n;
}