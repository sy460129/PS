#include <iostream>
using namespace std;
bool c;
int main(){
	int n, d=0, p=0; cin >> n;
	char x;
	while(n--){
		cin >> x;
		if(!c) x=='D' ? d++ : p++;
		if(abs(d-p)>=2) c=true;
	}
	cout << d << ":" << p;
}