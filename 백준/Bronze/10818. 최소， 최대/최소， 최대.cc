#include <iostream>
using namespace std;
int main() {
	int x, y, s=1000001, m=-1000001;
	cin >> x;
	while(x--){
		cin >> y;
		s=min(s,y);
		m=max(m,y);
	}
	cout << s << " " << m;
}