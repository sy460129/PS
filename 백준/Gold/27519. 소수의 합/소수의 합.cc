#include <iostream>
#include <vector>
using namespace std;
int dp[100001];
bool p[100001];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	v.push_back(2);
	for(int i=3; i<=100000; i+=2){
		if(!p[i]){
			v.push_back(i);
			for(int j=2; j<=100000/i; j++) p[i*j]=1;
		}
	}
	dp[0]=1;
	for(int i=0; i<v.size(); i++){
		for(int j=1; j<=100000; j++){
			if(j<v[i]) continue;
			dp[j]=(dp[j]+dp[j-v[i]])%1000000007;
		}
	}
	int n, x; cin >> n;
	while(n--){
		cin >> x;
		cout << dp[x] << "\n";
	}
}
