#include <iostream>
#include <vector>
using namespace std;
bool dp[1000001];
int su[101][101];
int n;
vector<int>v;
void check(int i, int j){
	int m;
	bool c;
	for(int k=0; k<v.size(); k++){
		c=true;
		m=v[k];
		for(int x=0; x<n*n; x++){
			if(!su[x][j]) continue;
			if(!(su[x][j]%m) || !(m%su[x][j])){
				c=!c;
				break;
			}
		}
		if(!c) continue;
		for(int y=0; y<n*n; y++){
			if(!su[i][y]) continue;
			if(!(su[i][y]%m) || !(m%su[i][y])){
				c=!c;
				break;
			}
		}
		if(!c) continue;
		for(int x=(i/n)*n; x<(i/n)*n+n; x++){
			for(int y=(j/n)*n; y<(j/n)*n+n; y++){
				if(!su[x][y]) continue;
				if(!(su[x][y]%m) || !(m%su[x][y])){
					c=!c;
					break;
				}
			}
		}		
		if(!c) continue;
		su[i][j]=m;
		return;
	}	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i=2; i<1000001; i++){
		if(!dp[i]){
			v.push_back(i);
			for(int j=2; j<=1000001/i; j++) dp[i*j]=1;
		}
	}
	cin >> n;
	for(int i=0; i<n*n; i++){
		for(int j=0; j<n*n; j++) cin >> su[i][j];
	}
	for(int i=0; i<n*n; i++){
		for(int j=0; j<n*n; j++){
			if(!su[i][j]) check(i,j);
		}
	}
	for(int i=0; i<n*n; i++){
		for(int j=0; j<n*n; j++) cout << su[i][j] << " ";
		cout << "\n";
	}
}