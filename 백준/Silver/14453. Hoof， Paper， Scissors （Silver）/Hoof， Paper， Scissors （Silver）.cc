#include <iostream>
using namespace std;
int H[100001];
int S[100001];
int P[100001];
int main(){
	char c;
	int n, ans=0; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> c;
		if(c=='H'){
			H[i]=H[i-1]+1;
			P[i]=P[i-1];
			S[i]=S[i-1];
		}
		else if(c=='P'){
			H[i]=H[i-1];
			P[i]=P[i-1]+1;
			S[i]=S[i-1];
		}
		else{
			H[i]=H[i-1];
			P[i]=P[i-1];
			S[i]=S[i-1]+1;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans=max(ans,max(P[n]-P[i], S[n]-S[i])+H[i]);
		ans=max(ans,max(P[n]-P[i], H[n]-H[i])+S[i]);
		ans=max(ans,max(H[n]-H[i], S[n]-S[i])+P[i]);
	}
	cout << ans;
}