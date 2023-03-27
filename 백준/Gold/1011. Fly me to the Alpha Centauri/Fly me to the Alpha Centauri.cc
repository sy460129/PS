#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,x,y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		y-=x;
		x=sqrt(y);
		if(x*x==y){
			cout << x*2-1;
		}
		else{
			if(x*x+x>=y){
				cout << x*2;
			}
			else{
				cout << x*2+1;
			}
		}
		cout << "\n";
	}
}
