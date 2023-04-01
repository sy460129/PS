#include <iostream>
using namespace std;
int main() {
	int n, x, y, ans=0;
	cin >> n;
	while(n--){
		cin >> x >> y;
		ans+=x*y;
	}
	cout << ans;
}