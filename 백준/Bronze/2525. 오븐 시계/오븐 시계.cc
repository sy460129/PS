#include <iostream>
using namespace std;
int main(){
	int n,m,x,t;
	cin >> n >> m >> x;
	if(m+x<60){
		cout << n << " " << m+x;
	}
	else{
		t=(m+x)/60;
		m=(m+x)%60;
		if(n+t<24){
			cout << n+t << " " << m;
		}
		else{
			cout << n+t-24 << " " << m;
		}
	}
}