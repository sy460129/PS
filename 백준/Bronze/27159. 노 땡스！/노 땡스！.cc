#include <iostream>
using namespace std;
int arr[34];
int main(){
	int n, ans=0; cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(i==0) ans=arr[i];
		else{
			if(arr[i]!=arr[i-1]+1) ans+=arr[i];
		}
	}
	cout << ans;
}