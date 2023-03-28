#include <iostream>
using namespace std;
int main() {
	int n,a,b,r=100,l=100;
	cin >> n;
	while(n--){
		cin >> a >> b;
		if(a>b){
			l-=a;
		}
		else if(a<b){
			r-=b;
		}
	}
	cout << r << "\n" << l;
}