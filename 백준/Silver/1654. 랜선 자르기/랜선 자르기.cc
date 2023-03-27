#include <iostream>
using namespace std;
typedef long long ll;
ll arr[10001];
int main(){
	ll n, k, e=1000001, s=1, res;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		e=max(arr[i], e);
	}
	while(s<=e){
		ll ans=0, m=(s+e)/2;
		for(int i=0; i<n; i++){
			ans+=arr[i]/m;
		}
		if(ans<k){
			e=m-1;
		}
		else{
			if(ans==k){
				res=m;
			}
			s=m+1;
		}
	}
	cout << e;
}