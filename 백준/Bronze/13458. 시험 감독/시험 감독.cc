#include <iostream>
using namespace std;
using ll=long long;
ll arr[1000001];
int main(){
	ll n, b, c, cnt=0; cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> b >> c;
	for(int i=0; i<n; i++){
		arr[i]=max((ll)0, arr[i]-b);
		cnt++;
		arr[i]%c!=0 ? cnt+=(arr[i]/c+1) : cnt+=arr[i]/c;
	}
	cout << cnt;
}