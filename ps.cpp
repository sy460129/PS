#include <iostream>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int r, a;
int main(){
    rep(i, 0, 3){
        rep(j, 0, 4){
            cin >> a;
            r+=a;
        }
        switch(r){
			case 3:
				cout << "A";
				break;
			case 2:
				cout << "B";
				break;
			case 1:
				cout << "C";
				break;
			case 4:
				cout << "D";
				break;
			case 0:
				cout << "E";
				break;
		}
		cout << "\n";
		r=0;
	}
}