#include<iostream>
using namespace std;
int Rev(int n, int s) {
	while(n!=0) {
		s*=10;
		s+=n%10;
		n/=10;
	}
	return s;
}
int main() {
	int X,Y;
	int Q=0, S=0, A=0;
	cin >>X>>Y;
	A=Rev(Rev(X,Q)+Rev(Y,S),A);
	cout << A;
}