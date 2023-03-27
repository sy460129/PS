#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[500001];
int a[8002];
int main(){
	int ma=-4001, mi=4001, n, x, ans, res=0;
	double t=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		t+=x;
		arr[i]=x;
		x+=4000;
		a[x]++;
		ma=max(ma,arr[i]);
		mi=min(mi,arr[i]);
	}
	sort(arr, arr+n);
	bool c=false;
	for(int i=0; i<=8001; i++){
		if(a[i] > res){
			c=false;
			res=a[i];
			ans=i;
		}
		else if(a[i]==res){
			if(!c){
				c=true;
				ans=i;
			}
		}
	}
	if(round(t/n) == 0){
		cout << 0 << "\n";
	}
	else{
		cout << round(t/n) << "\n";
	}
	cout << arr[n/2] << "\n" << ans-4000 << "\n" << ma-mi;
}