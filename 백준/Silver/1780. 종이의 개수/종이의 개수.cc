#include <iostream>
using namespace std;
int arr[2200][2200];
int c0, c1, c2;
bool c;
void dv(int x, int y, int n){
	c=true;
	int t=arr[x][y];
	for(int i=x; i<x+n; i++){
		if(!c) break;
		for(int j=y; j<y+n; j++){
			if(arr[i][j]!=t){
				c=false;
				break;
			}
		}
	}
	if(!c){
		dv(x, y, n/3);
		dv(x, y+n/3, n/3);
		dv(x, y+2*n/3, n/3);
		dv(x+n/3, y, n/3);
		dv(x+n/3, y+n/3, n/3);
		dv(x+n/3, y+2*n/3, n/3);
		dv(x+2*n/3, y, n/3);
		dv(x+2*n/3, y+n/3, n/3);
		dv(x+2*n/3, y+2*n/3, n/3);
	}
	else{
		if(t==-1) c0++;
		else if(t==0) c1++;
		else c2++;
	}
	return;
}
int main(){
	int h; cin >> h;
	for(int i=0; i<h; i++){
		for(int j=0; j<h; j++){
			cin >> arr[i][j];
		}
	}
	dv(0, 0, h);
	cout << c0 << "\n" << c1 << "\n" << c2;
}