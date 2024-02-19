#include <iostream>
#include <string>
using namespace std;
int dp[41];
int main(){
	int n, t;
	string s; cin >> s;
	n=s[0]-'0';
	if(n>0 && n<10) dp[0]=1;
	n*=10;
	n+=s[1]-'0';
	if(n>9 && n<35) dp[1]=1;
	n=s[1]-'0';
	if(n>0 && n<10) dp[1]++;
	for(int i=2; i<s.length(); i++){
		n=s[i]-'0';
		if(n>0 && n<10) dp[i]=dp[i-1];
		t=s[i-1]-'0';
		t*=10;
		n+=t;
		if(n>9 && n<35) dp[i]+=dp[i-2];
	}
	cout << dp[s.length()-1];
}