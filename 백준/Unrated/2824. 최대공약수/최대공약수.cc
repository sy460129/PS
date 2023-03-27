#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long arr[1001], brr[1001];
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	int n, m;
	long long cnt, res, ans=1; cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> m;
	for(int i=0; i<m; i++) cin >> brr[i];
	for(int i=0; i<n; i++){
		res=1;
		for(int j=0; j<m; j++){
			cnt=0;
			cnt=gcd(arr[i],brr[j]);
			arr[i]/=cnt;
			brr[j]/=cnt;
			res*=cnt;
			if(arr[i]==1) break;
		}
		ans*=res;
		ans%=10000000000;
	}
	if(ans/1000000000!=0){	
		string s=to_string(ans);
		reverse(s.begin(), s.end());
		s.pop_back();
		reverse(s.begin(), s.end());
		cout << s;
	}
	else cout << ans;
}