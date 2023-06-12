#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];
int main(){
	int n, a, b; cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];
	sort(arr, arr+n+1);
	if(n==1) cout << arr[1];
	else if(n==2) cout << arr[2]+arr[1]-1;
	else{
		a=n/3;
		b=n/3*2;
		if(n%3==2) b++;
		cout << arr[n]+arr[a]+arr[b]-3;
	}	
}