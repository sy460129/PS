#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	double p, pab, pbc, pcd;
	cin >> pab >> pbc >> pcd;
	p = (pab * pcd) / pbc;
	cout << fixed << setprecision(6) << p;
}