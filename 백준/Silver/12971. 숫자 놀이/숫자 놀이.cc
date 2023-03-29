#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int P1, P2, P3, X1, X2, X3, N;
	cin >> P1 >> P2 >> P3 >> X1 >> X2 >> X3;
	N=P3;
	P3+=X3;
	if(X3 % P1 == X1 && X3 % P2 == X2){
		cout << X3;
		return 0;
	} 
	while (1) {
		if (P3 % P1 == X1 && P3 % P2 == X2) {
			cout << P3;
			break;
		}
		else {
			P3 += N;
		}
		if (P3 >= 1000000000) {
			cout << -1;
			break;
		}
	}
}