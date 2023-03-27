#include <iostream>
using namespace std;
int main(){
	int n, cnt=1, ans=666, t;
	cin >> n;
	while(n!=cnt){
		ans++;
		t=ans;
		while(t!=0){
			if(t%1000==666){
				cnt++;
				break;
			}
			t/=10;
		}
	}
	cout << ans;
}