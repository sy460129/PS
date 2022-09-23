#include <iostream>
using namespace std;
int arr[1001];
int brr[1001];
int main(){
	int n, m, ans=0;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<m; i++){
		cin >> brr[i];
	}
	for(int i=0; i<m; i++){
		ans=max(ans, brr[i]-arr[i]);
	}
	ans>0 ? cout << ans : cout << 0;
}