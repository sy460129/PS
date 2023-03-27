#include <iostream>
using namespace std;
int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n, m, ans=0; cin >> n >> m;
	for(int i=0; i<n; i++){
		m+=arr[i];
	}
	switch(m%7){
		case 1:
			cout << "MON";
			break;
		case 2:
			cout << "TUE";
			break;
		case 3:
			cout << "WED";
			break;
		case 4:
			cout << "THU";
			break;
		case 5:
			cout << "FRI";
			break;
		case 6:
			cout << "SAT";
			break;
		default:
			cout << "SUN";
			break;
	}
}