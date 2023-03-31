#include <iostream>
using namespace std;
char arr[11][11], brr[44][44];
int ans, cnt, o;
int main(){
	int n, m, n2, m2; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j]!='.') o++;
		}
	}
	cin >> n2 >> m2;
	for(int i=0; i<44; i++){
		for(int j=0; j<44; j++){
			if(i>10 && i<n2+11 && j>10 && j<m2+11) cin >> brr[i][j];
			else brr[i][j]='.';
		}
	}
	for(int i=0; i<34; i++){
		for(int j=0; j<34; j++){
			cnt=0;
			for(int k=0; k<n; k++){
				for(int l=0; l<m; l++){
					if(arr[k][l]==brr[k+i][l+j] && arr[k][l]!='.') cnt++;
				}
			}
			ans=max(ans, cnt);
		}
	}
	cout << o-ans;
}