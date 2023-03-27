#include <iostream>
using namespace std;
int arr[10000001];
int brr[10000001];
int main(){
	int n, t=2, i=2, k=1, a=3, p=3;
	cin >> n;
	arr[1]=1, brr[1]=1;
	while(t!=n+1){
		arr[t]=k;
		brr[t]=i-k+1;
		if(i%2==0){
			k++;
		}
		else{
			k--;
		}
		if(t==a){
			i++;
			if(i%2!=0){
				k=i;
			}
			else{
				k=1;
			}
			a+=p;
			p++;
		}
		t++;
	}
	cout << arr[n] << "/" << brr[n];
}