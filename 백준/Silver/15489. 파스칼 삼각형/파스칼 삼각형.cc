#include <iostream>
using namespace std;
int com[32][32];
int main(){
	for(int i=1; i<=30; i++){
		for(int j=1; j<=i; j++){
			if(i==1 || j==1) com[i][j]=1;
			else com[i][j]=com[i-1][j-1]+com[i-1][j];
		}
	}
	int n, m, r, t=1, ans=0; cin >> n >> m >> r;
	for(int i=n; i<n+r; i++){
		for(int j=m; j<m+t; j++) ans+=com[i][j];
		t++;
	}
	cout << ans;
}