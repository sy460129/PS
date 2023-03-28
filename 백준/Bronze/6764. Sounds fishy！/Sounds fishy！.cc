#include <iostream>
using namespace std;
int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==b && b==c && c==d){
		cout << "Fish At Constant Depth";
		return 0;
	}
	else if(a>b){
		if(b>c){
			if(c>d){
				cout << "Fish Diving";
				return 0;
			}
		}
	}
	else if(a<b){
		if(b<c){
			if(c<d){
				cout << "Fish Rising";
				return 0;
			}
		}
	}
	cout << "No Fish";
}