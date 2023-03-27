#include <iostream>
using namespace std;
int arr[31];
int brr[31];
int main(){
	int n, k, p, q;
	cin >> n >> k;
	arr[1]=1;
	brr[2]=1;
	arr[3]=1, brr[3]=1;
	for(int i=4; i<=n; i++){
		arr[i]=arr[i-1]+arr[i-2];
		brr[i]=brr[i-1]+brr[i-2];
	}
	p=arr[n], q=brr[n];
	for(int i=1; i<=k; i++){
		if((k-p*i)%q==0){
			cout << i << "\n" << (k-p*i)/q;
			return 0;
		}
	}
}