#include <iostream>
using namespace std;
int a[51][51];
int b[51][51];
void d(int x, int y){
	for(int i=x; i<x+3; i++){
		for(int j=y; j<y+3; j++){
			if(a[i][j]==0){
				a[i][j]=1;
			}
			else{
				a[i][j]=0;
			}
		}
	}
}
int main(){
	int n,m,c=0;
	string s;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			a[i][j]=s[j]-'0';
		}
	}
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			b[i][j]=s[j]-'0';
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j=0; j<m-2; j++){
			if(a[i][j]!=b[i][j]){
				c++;
				d(i,j);
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=b[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << c;
}