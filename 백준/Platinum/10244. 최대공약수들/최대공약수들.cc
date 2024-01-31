#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool check[101];
int gcd(int x, int y){
	return !y ? x : gcd(y, x%y);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x;
	while(1){
		set<int>s;
		cin >> n;
		if(!n) break;
		int* dp=new int[n];
		for(int i=0; i<n; i++){
			cin >> dp[i];
			s.insert(dp[i]);
			check[dp[i]]=true;
		}
		for(int i=1; i<101; i++){
			if(check[i]) continue;
			x=dp[0];
			for(int j=1; j<n; j++){
				x=gcd(x, dp[j]);
				if(x%i) x=dp[j];
				if(!check[x]){
					check[x]=true;
					s.insert(x);
				}
			}
		}
		delete[] dp;
		fill(check, check+101, 0);
		cout << s.size() << "\n";
	}
}