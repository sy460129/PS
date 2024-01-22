#include <iostream>
using namespace std;
int main(){
	int n, i=2;
	cin >> n;
	if(n%6!=2 && n%6!=3){
		if(n%2==0){
			while(1){
				cout << i << "\n";
				i+=2;
				if(i>n){
					i=1;
				}
				if(i==n-1){
					cout << i;
					break;
				}
			}	
		}
		else{
			while(1){
				cout << i << "\n";
				i+=2;
				if(i>n){
					i=1;
				}
				if(i==n){
					cout << i;
					break;
				}
			}
		}
	}
	else{
		if(n%6==2){
			while(1){
				cout << i << "\n";
				if(i==n-1){
					cout << 5;
					break;
				}
				i+=2;
				if(i>n){
					i=7;
					cout << 3 << "\n" << 1 <<" \n";
				}
			}
		}
		else{
			i=4;
			while(1){
				cout << i << "\n";
				if(i==n){
					cout << 1 << "\n" << 3;
					break;
				}
				i+=2;
				if(i>n){
					i=5;
					cout << 2 << "\n";
				}
			}
		}
	}
}