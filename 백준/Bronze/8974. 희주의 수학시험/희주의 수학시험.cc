#include <iostream>
using namespace std;
int dp[1001];
int main(){
	int a, b, j=1, k=1, ans=0; cin >> a >> b;
	for(int i=1; i<=1000; i++){
		dp[i]=k, j--;
		if(!j) k++, j=k;
	}
	for(int i=a; i<=b; i++) ans+=dp[i];
	cout << ans;
}