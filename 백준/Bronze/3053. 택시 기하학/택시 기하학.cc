#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	double x;
	cin >> x;
	cout << fixed << setprecision(6) << x*x*3.141592653589794832 << "\n";
	cout << x*x*2;
}