#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, l, ans=0;
	cin >> n;
	int* arr= new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cin >> l;
	for(int i=0; i<n; i++){
		if(l<arr[i]){
			ans=(l-arr[i-1])*(arr[i]-l)-1;
			cout << max(0,ans);
			return 0;
		}
	}
	cout << 0;
}