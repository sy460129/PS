#include <iostream>
using namespace std;
int main(){
	int v, v2, m, t, x=0, y=0; cin >> v2 >> m >> t;
	int d[4];
	v=v2;
	for(int i=1; i<=4; i++){
		v=(v*m)%10;
		if(i!=4) d[i]=v;
		else d[0]=v;
	}
	m=t/4, t%=4;
	y+=(d[0]-d[2])*m;
	x+=(d[1]-d[3])*m;
	if(t>=1){
		y+=d[0];
		if(t>=2){
			x+=d[1];
			if(t>=3) y-=d[2];
		}
	}
	y+=v2-d[0];
	cout << x << " " << y;
}