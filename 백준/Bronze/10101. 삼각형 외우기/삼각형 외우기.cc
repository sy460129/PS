#include <iostream>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b&&b==c&&a==60){
		cout<<"Equilateral";
	}
	else if(a==c||a==b||b==c){
		if(a+b+c==180){
			cout<<"Isosceles";
		}
		else{
			cout<<"Error";
		}
	}
	else if(a+b+c==180){
		cout<<"Scalene";
	}
	else{
		cout<<"Error";
	}
}