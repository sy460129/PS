#include <iostream>
using namespace std;
pair<int,int>arr[11];
int n, x, y, s, b, ans=2147483647;
void dfs(int t){
	for(int i=t+1; i<n; i++){
		s*=arr[i].first, b+=arr[i].second;
		ans=min(ans, abs(s-b));
		dfs(i);
		s/=arr[i].first, b-=arr[i].second;
	}
}
int main(){
	 cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		arr[i]={x,y};
	}
	for(int i=0; i<n; i++){
		s=arr[i].first, b=arr[i].second;
		ans=min(abs(s-b),ans);
		dfs(i);
	}
	cout << ans;
}