#include <iostream>
using namespace std;
int arr[1001];
int main() {
	int n, x, ans = 0, a;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	a=1001;
	for(int i=1; i<n; i++){
		if(arr[i]>arr[i-1]){
			a=min(a, arr[i-1]);
		}
		else{
			ans=max(arr[i-1]-a, ans);
			a=1001;
		}
	}
	if(arr[n-1]>arr[n-2]){
		ans=max(arr[n-1]-a, ans);
	}
	cout << ans;
}