#include <iostream>
using namespace std;
int main(){
	int a, b, c, cnt=0; cin >> a >> b >> c;
	while(1){
		if(a+1==b && b+1==c) break;
		if(b-a>=c-b){
			c=b-1;
			swap(b, c);
			cnt++;
		}
		else{
			a=b+1;
			swap(a, b);
			cnt++;
		}
	}
	cout << cnt;
}