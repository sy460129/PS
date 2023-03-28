#include<iostream>
#include<algorithm>
using namespace std;
int n[3];
int main(){
	int n;
	cin >> n;
	while(n--){
		int x,m=101,s=0;
		for(int i=0; i<7; i++){
			cin >> x;
			if(x%2==0){
				s+=x;
				m=min(x,m);
			}
		}
		cout << s << " " << m << "\n";
	}
}