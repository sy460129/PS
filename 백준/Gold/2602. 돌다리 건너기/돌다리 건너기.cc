#include <iostream>
using namespace std;
int angel[101][101];
int devil[101][101];
string s, a, d;
int t, ans;
int dfs(int n, int t, bool c){
	if(t==s.length()) return 1;
	int sum=0;
	!c ? sum=angel[n][t] : sum=devil[n][t];
	if(sum) return sum;
	if(!c){
		for(int i=n; i<d.length(); i++){
			if(d[i]==s[t]){
				sum+=dfs(i+1, t+1, 1);
			}
		}
	}
	else{
		for(int i=n; i<a.length(); i++){
			if(a[i]==s[t]){
				sum+=dfs(i+1, t+1, 0);
			}
		}
	}
	return !c ? angel[n][t]=sum  : devil[n][t]=sum;
}
int main(){
	cin >> s >> a >> d;
	for(int i=0; i<a.length(); i++){
		if(a[i]==s[t]){
			angel[i][t]=dfs(i+1, t+1, 0);
		}
	}
	for(int i=0; i<d.length(); i++){
		if(d[i]==s[t]){
			devil[i][t]=dfs(i+1,t+1, 1);
		}
	}
	for(int i=0; i<a.length(); i++){
		ans+=devil[i][0]+angel[i][0];
	}
	cout << ans;
}