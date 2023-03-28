#include <iostream>
using namespace std;
int arr[101001];
int main(){
	int n, x,i=0;
	char c;
	cin >> n >> x;
	while(n!=0){
		arr[i]=n%x;
		n/=x;
		i++;
	}
	for(int j=i-1; j>=0; j--){
		if(arr[j]>=10){
			c=(arr[j]-10)+'A';
			cout << c;
		}
		else{
			cout << arr[j];
		}
	}
}