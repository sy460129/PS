#include <iostream>
#include <cmath>
using namespace std;
int cnt=0, h, r, c;
void dv(int x, int y, int n) {
	/*if(x==r && y==c){
		cout << cnt;
		exit(0);
	}*/
	if(n<=2){
		for (int i=x; i<n+x; i++){
			for (int j=y; j<n+y; j++){
				if(i==r && j==c){
					cout << cnt;
					exit(0);
				}
				else{
					cnt++;
				}
			}
		}
	}
	else {
		if(r<x+n/2 && c<y+n/2){
			dv(x, y, n/2);
		}
		cnt+=n*(n/4);
		if(r<x+n/2 && c>=y+n/2){
			dv(x, n/2+y, n/2);
		}
		cnt+=n*(n/4);
		if(r>=x+n/2 && c<y+n/2){
			dv(n/2+x, y, n/2);
		}
		cnt+=n*(n/4);
		if(r>=x+n/2 && c>=y+n/2){
			dv(n/2+x, n/2+y, n/2);
		
		}
	}
}
int main() {
	cin >> h >> r >> c;
	h=pow(2,h);
	dv(0, 0, h);
}