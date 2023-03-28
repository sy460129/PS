#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>v;
int arr[10][10];
bool check(int x, int y, int i){
	for(int j=0; j<9; j++){
		if(arr[x][j]==i || arr[j][y]==i){
			return false;
		}
	}
	int a=(x/3)*3, b=(y/3)*3;
	for(int j=a; j<a+3; j++){
		for(int k=b; k<b+3; k++){
			if(arr[j][k]==i){
				return false;
			}
		}
	}
	return true;
}
void sudoku(int n){
	if(n==v.size()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int x = v[n].first, y = v[n].second;
	for(int i=1; i<=9; i++){
		if(check(x,y,i)){
			arr[x][y]=i;
			sudoku(n+1);
		}
	}
	arr[x][y]=0;
	return;
}
int main() {
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> arr[i][j];
			if(arr[i][j]==0){
				v.push_back({i,j});
			}
		}
	}
	sudoku(0);
}