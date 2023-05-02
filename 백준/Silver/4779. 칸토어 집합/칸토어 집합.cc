#include <iostream>
#include <cmath>
using namespace std;
void check(int n){
	if(n%3==1) cout << " ";
	else if(n>=3) check(n/3);
	else cout << "-";
}
int main(){
	int n;
	while(cin >> n){
		n=pow(3,n);
		for(int i=0; i<n; i++){
			check(i);
		}
		cout << "\n";
	}
}