#include <iostream>
using namespace std;
int main(){
	int n, m;
	while(1){
		cin >> n >> m;
		if(!n && !m){
			break;
		}
		if(n>m){
			n%m==0 ? cout << "multiple" : cout << "neither";
		}
		else {
			m%n==0 ? cout << "factor" : cout << "neither";
		}
		cout << "\n";
	}
}