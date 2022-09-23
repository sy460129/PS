#include <iostream>
#include <vector>
using namespace std;
vector<int>v(3);
int main() {
	int ans=0;
	for(int i=0; i<3; i++){
		cin >> v[i];
		if(v[i]%2!=0){
			if(ans==0) ans=1;
			ans*=v[i];
		}
	}
	if(ans==0){
		ans=1;
		for(int i=0; i<3; i++){
			ans*=v[i];
		}
	}
	cout << ans;
}