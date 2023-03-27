#include <iostream>
using namespace std;
int main(){
	int n,m,x,t,y;
	cin >> n >> m >> x >> y;
	x+=y;
	if(x>=60){
		t=x/60;
		x%=60;
		m+=t;
		if(m>=60){
			t=m/60;
			m%=60;
			n+=t;
			if(n>=24){
				n%=24;
			}
		}
	}
	cout << n << " " << m << " " << x;
}