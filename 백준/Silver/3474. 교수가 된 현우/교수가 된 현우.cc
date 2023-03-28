#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while(t--){
		int ans=0;
		cin >> n;
		while(n/5){
			ans+=n/5;
			n/=5;
		}
		cout << ans << "\n";
	}
}