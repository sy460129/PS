#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>v, vec;
int arr[10][10];
bool c;
bool precheck(int p, int q, int n){
	for(int i=0; i<9; i++){
		if((i!=p &&arr[i][q] == n) || (i!=q && arr[p][i] == n)){
			return false;
		}
	}
	int a=(p/3)*3, b=(q/3)*3;
	for(int i=a; i<a+3; i++){
		for(int j=b; j<b+3; j++){
			if(i!=p && j!=q && arr[i][j]==n){
				return false;
			}
		}
	}
	return true;
}
bool check(int x, int y, int n){
	for(int i=0; i<9; i++){
		if(arr[i][y] == n || arr[x][i] == n){
			return false;
		}
	}
	int a=(x/3)*3, b=(y/3)*3;
	for(int i=a; i<a+3; i++){
		for(int j=b; j<b+3; j++){
			if(arr[i][j]==n){
				return false;
			}
		}
	}
	return true;
}
void sudoku(int n){
	if(n==v.size()){
		c=true;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	int x=v[n].first, y=v[n].second;
	for(int i=1; i<=9; i++){
		if(check(x,y,i)){
			arr[x][y]=i;
			sudoku(n+1);
		}
	}
	arr[x][y]=0;
	return;
}
int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		c=true;
		for(int i=0; i<9; i++){
			cin >> s;
			for(int j=0; j<9; j++){
				arr[i][j]=s[j]-'0';
				if(arr[i][j]==0){
					v.push_back({i,j});
				}
			}
		}
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(arr[i][j]==0){
					continue;
				}
				else if(!precheck(i, j, arr[i][j])){
					c=false;
				}
			}
		}
		if(c){
			sudoku(0);
		}
		else{
			cout << "Could not complete this grid.\n\n";
		}
		v=vec;
	}
}