#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string dp[251];
string str(string s, string c){
	string r, ans;
	int x, y=0, z;
	reverse(s.begin(), s.end());
	reverse(c.begin(), c.end());
	for(int i=0; i<s.length(); i++){
		x=(s[i]-'0')*2+y;
		y=x/10;
		z=x%10;
		r+=to_string(z);
	}
	if(y) r+='1';
	y=0;
	while(r.length()>c.length()) c+='0';
	while(r.length()<c.length()) r+='0';
	for(int i=0; i<r.length(); i++){
		x=(r[i]-'0'+c[i]-'0'+y);
		y=x/10;
		z=x%10;
		ans+=to_string(z);
	}
	if(y) ans+='1';
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	int n;
	dp[0]='1', dp[1]='1', dp[2]='3';
	for(int i=3; i<=250; i++){
		dp[i]=str(dp[i-2],dp[i-1]);
	}
	while(cin >> n){
		cout << dp[n] << "\n";
	}
}