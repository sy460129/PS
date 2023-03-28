#include <iostream>
using namespace std;
int main() {
	int n,a,c=0;
	cin >> n;
	while(n--){
		cin >> a;
		if(a==0){
			c++;
		}
		else{
			c--;
		}
	}
	if(c>0){
		cout << "Junhee is not cute!";
	}
	else{
		cout << "Junhee is cute!";
	}
}