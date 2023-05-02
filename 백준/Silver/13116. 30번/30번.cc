#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, x, y; cin >> t;
	while(t--){
		cin >> x >> y;
		while(x!=y){
			if(x>y) x/=2;
			else y/=2;
		}
		cout << x*10 << "\n";
	}
}