#include <iostream>
using namespace std;
int main(){
	int n, x=0, i=1; cin >> n;
	while(1){
		x+=i;
		if(x>n) break;
		i++;
	}
	i%2==0 ? cout << 0 : cout << x-n;
}