#include <iostream>
using namespace std;
int main() {
	int x, y, z, ans;
	cin >> x >> y >> z;
	ans = (z - x) / (x - y);
	if((z - x) % (x - y) != 0){
		ans += 1;
	}
	cout << ans + 1;
}