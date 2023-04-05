#include <iostream>
using namespace std;
int main(){
	char x;
	int n; cin >> n;
	while(1){
		cout << "? " << 1 << "\n";
		cout << flush;
		cin >> x;
		if(x=='Y'){
			cout << "! " << 1;
			cout << flush;
			return 0;
		}
	}
}