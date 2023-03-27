#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i=1; i<n; i++){
		int x=i, y=i;
		while(x!=0){
			y+=x%10;
			x/=10;
		}
		if(y==n){
			cout << i;
			return 0;
		}
	}
	cout << 0;
}