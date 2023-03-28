#include <iostream>
using namespace std;
int a[3];
int main() {
	int n, cnt=0;
	cin >> n;
	for(int i=1; i<=n; i++){
		a[0]=i;
		int j=i;
		while(1){
			a[1]=j, a[2]=n-i-j;
			if(a[1]>a[2]) break;
			if(a[0]+a[1]>a[2]) cnt++;
			j++;
		}
	}
	cout << cnt;
}