#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int n;
	double x;
	cin >> n;
	while(n--){
		cin >> x;
		cout << fixed << setprecision(2) << "$" << x*4/5 << "\n";
	}
}