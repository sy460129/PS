#include <iostream>
using namespace std;
int main() {
	int n,a,b,c;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		if(a<b-c){
			cout << "advertise\n";
		}
		else if(a==b-c){
			cout << "does not matter\n";
		}
		else{
			cout << "do not advertise\n";
		}
	}
}