#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int x, a, b, c, d; cin >> x >> a >> b >> c >> d;
	if(a*x+b==c*x+d) cout << "Yes " << a*x+b;
	else cout << "No";
}