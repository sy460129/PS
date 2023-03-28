#include <iostream>
using namespace std;
int main(){
	int n, m, k, cnt=0, c=0; cin >> n >> m >> k;
	while(n!=1){
		n/=2;
		cnt++;
	}
	while(1){
		if(!k || k==1) break;
		k/=2, c++;
	}
	cout << min(cnt, c+m);
}