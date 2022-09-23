#include <iostream>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	k-=3;
	if(k>=0){
		for(int i=0; i<k; i++){
			m++;
			if(m>n){
				m=1;
			}
		}
	}
	else{
		k*=-1;
		for(int i=0; i<k; i++){
			m--;
			if(m==0){
				m=n;
			}
		}
	}
	cout << m;
}