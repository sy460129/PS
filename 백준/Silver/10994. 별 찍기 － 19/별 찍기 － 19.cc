#include <iostream>
using namespace std;
char arr[401][401];
int n;
void dfs(int t){
	if(t>4*(n-1)+1){
		for(int i=0; i<4*(n-1)+1; i++){
			for(int j=0; j<4*(n-1)+1; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	for(int i=t; i<4*(n-1)-t+1; i++){
		for(int j=t; j<4*(n-1)-t+1; j++){
			if(i==t || i==4*(n-1)-t) arr[i][j]='*';
			else{
				if(j==t || j==4*(n-1)-t) arr[i][j]='*';
				else arr[i][j]=' ';
			}
		}
	}
	dfs(t+2);
}
int main(){
	 cin >> n;
	if(n==1){
		cout << "*";
		return 0;
	}
	int t=4*(n-1)+1;
	dfs(0);
}