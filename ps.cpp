#include <iostream>
#include <algorithm>
using namespace std;
using ull=unsigned long long;
ull arr[200001];
ull gcd(ull a, ull b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ull n, m, x, g=0;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i=1; i<n; i++){
		g=gcd(arr[i]-arr[0], g);
	}
	for(int i=0; i<m; i++){
		cin >> x;
		cout << gcd(arr[0]+x, g) << " ";
	}
}