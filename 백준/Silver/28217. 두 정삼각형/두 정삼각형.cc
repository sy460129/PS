#include <iostream>
using namespace std;
int a[11][11], b[11][11], tmp[11][11];
int main(){
	int n, cnt, ans=0; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin >> a[i][j];
			tmp[i][j]=a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin >> b[i][j];
			if(a[i][j]!=b[i][j]) ans++;
		}
	}
	int t=3;
	while(t--){
		cnt=0;
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				tmp[j][i]=a[n-i-1][j-i];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				if(tmp[i][j]!=b[i][j]) cnt++;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				a[i][j]=tmp[i][j];
			}
		}
		ans=min(ans, cnt);
	}
	t=3;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i/2; j++){
			swap(a[i][j], a[i][i-j]);
		}
	}
	while(t--){
		cnt=0;
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				tmp[j][i]=a[n-i-1][j-i];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				if(tmp[i][j]!=b[i][j]) cnt++;
			}
		}
		ans=min(ans, cnt);
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				a[i][j]=tmp[i][j];
			}
		}
	}
	cout << ans;
}