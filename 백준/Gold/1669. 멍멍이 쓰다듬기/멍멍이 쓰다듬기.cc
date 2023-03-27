#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	m-=n;
	if(m==0){
		cout << 0;
		return 0;
	}
	int s=sqrt(m);
	if(s*s==m){
		cout << s*2-1;
	}
	else{
		if(s*s+s<m){
			cout << s*2+1;
		}
		else{
			cout << s*2;
		}
	}
}