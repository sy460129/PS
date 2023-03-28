#include <iostream>
using namespace std;
int main() {
	int n,a,b;
	cin >> n;
	while(n--){
		int x=0, y=0;
		for(int i=0; i<9; i++){
			cin >> a >> b;
			x+=a, y+=b;
		}
		if(x>y){
			cout << "Yonsei\n";
		}
		else if(x<y){
			cout << "Korea\n";
		}
		else{
			cout << "Draw\n";
		}
	}
}