#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int* arr=new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int f=1, e=arr[n-1], m, ans=0;
	while(f<=e){
		int cnt=1, x1=arr[0];
		m=(f+e)/2;
		for(int i=1; i<n; i++){
			if(arr[i]-x1>=m){
				cnt++;
				x1=arr[i];
			}
		}
		if(cnt>=k){
			ans=max(ans, m);
			f=m+1;
		}
		else{
			e=m-1;
		}
	}
	cout << ans;
}