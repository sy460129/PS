#include <iostream>
using namespace std;
int main(){
	int t, w, h, x;
	cin >> t;
	while(t--){
		cin >> w >> h >> x;
		if(x%w==0){
			cout << w * 100 + x / w << "\n";
		}
		else{
			cout << (x % w) * 100 + x / w + 1 << "\n";
		}
	}
}