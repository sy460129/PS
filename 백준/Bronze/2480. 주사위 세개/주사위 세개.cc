#include <iostream>
using namespace std;
int ar[7];
int main(){
	int a,b,c,t=-1;
	cin >> a>>b>>c;
	ar[a]++,ar[b]++,ar[c]++;
	for(int i=1; i<=6; i++){
		if(ar[i]==3){
			cout << 10000+i*1000;
			return 0;
		}
		else if(ar[i]==2){
			cout << 1000+i*100;
			return 0;
		}
		else if(ar[i]==1){
			t=max(t,i);
		}
	}
	cout << t*100;
}