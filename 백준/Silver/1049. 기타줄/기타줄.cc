#include <iostream>
using namespace std;

int main() {
	int n, m, x, y, six=1001, one=1001;
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		six=min(x,six);
		one=min(one,y);
	}
	cout << min((n/6)*six + (n%6)*one, min(one*n, ((n/6)+1)*six));
}