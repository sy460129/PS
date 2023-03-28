#include <iostream>
using namespace std;
int main() {
	int a, b, n, x, ans; cin >> a >> b >> n;
	ans=abs(a-b);
	for(int i=0; i<n; i++){
		cin >> x;
		ans=min(ans,abs(b-x)+1);
	}
	cout << ans;
}