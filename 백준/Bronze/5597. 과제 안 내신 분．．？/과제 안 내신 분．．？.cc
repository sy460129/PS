#include <iostream>
using namespace std;
bool a[31];
int main() {
	int x;
	for(int i=0; i<28; i++){
		cin >> x;
		a[x]=1;
	}
	for(int i=1; i<31; i++){
		if(!a[i]){
			cout << i <<" \n";
		}
	}
}