#include <iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	for(int i=0; i<3; i++){
		cin >> a>>b>>c>>d>>e>>f;
		if(f<c){
			e--;
			f+=60;
		}
		if(e<b){
			d--;
			e+=60;
		}
		cout << d-a << " " << e-b << " " << f-c << "\n";
	}
}