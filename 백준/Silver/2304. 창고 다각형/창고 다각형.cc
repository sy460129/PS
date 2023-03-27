#include <iostream>
using namespace std;
int arr[1001], brr[1001];
pair<int,int>p;
int main(){
	int n, x, y, m=-1, m2=-1, ans=0; cin >> n;
	while(n--){
		cin >> x >> y;
		arr[x]=y;
		brr[x]=y;
	}
	for(int i=0; i<1001; i++){
		arr[i]=max(arr[i], m);
		if(arr[i]>m){
			p={m,i};
			m=arr[i];
		}
	}
	for(int i=1000; i>=p.second; i--){
		brr[i]=max(brr[i], m2);
		m2=max(brr[i], m2);
	}
	for(int i=0; i<1001; i++) {
		if(i<=p.second) ans+=arr[i];
		else ans+=brr[i];
	}
	cout << ans;
}