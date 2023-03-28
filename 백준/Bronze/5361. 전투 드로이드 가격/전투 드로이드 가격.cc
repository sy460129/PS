#include <iostream>
#include <iomanip>
using namespace std;
double p[5];
int main(){
	int n, a, b, c, d, e; cin >> n;
	p[0] = 350.34;
	p[1] = 230.90;
	p[2] = 190.55;
	p[3] = 125.30;
	p[4] = 180.90;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e;
		cout << "$" << fixed << setprecision(2) << a * p[0] + b * p[1] + c * p[2] + d * p[3] + e * p[4] << "\n";
	}
}