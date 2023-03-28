#include <iostream>
using namespace std;
bool c[200001];
int main(){
	int n, x, y, cnt=0; cin >> n;
	while(n--){
		cin >> x >> y;
		if(c[x]){
			y ? cnt++ : c[x]=false;
		}
		else{
			y ? c[x]=true : cnt++;
		}
	}
	for(int i=1; i<=200000; i++) if(c[i]) cnt++;
	cout << cnt;
}