#include <iostream>
using namespace std;
int main() {
	int n=4,x,s=0;
	while(n--){
		cin>>x;
		s+=x;
	}
	cout<<s/60<<"\n"<<s%60;
}