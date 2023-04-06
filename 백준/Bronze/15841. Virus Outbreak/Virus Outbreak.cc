#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string dp[500];
string str(string x, string y) {
	string ans;
	int t, n=0;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while(x.length()<y.length()) x+='0';
	while(x.length()>y.length()) y+='0';
	for(int i=0; i<x.length(); i++){
		t=(x[i]-'0'+y[i]-'0'+n)%10;
		ans+=to_string(t);
		n=(x[i]-'0'+y[i]-'0'+n)/10;
	}
	if(n) ans+='1';
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	int n;
	dp[0]="1", dp[1]="1";
	for(int i=2; i<=490; i++){
		dp[i]=str(dp[i-1],dp[i-2]);
	}
	while(1){
		cin >> n;
		if(n<0) break;
		cout << "Hour " << n << ": " << dp[n-1] << " cow(s) affected\n";
	}
}