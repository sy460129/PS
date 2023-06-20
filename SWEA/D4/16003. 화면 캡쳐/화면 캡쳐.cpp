#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, x;
vector<int>v;
void track(){
	int t=v.back();
	for(int i=0; i<10; i++){
		if(v.size()==min(x,50)) return;
		if(t*10+i<=x){
			v.push_back(t*10+i);
			track();
		}
		else return;
	}
}
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){		
		cin >> x;
		for(int j=1; j<=x; j++){
			if(v.size()==min(x,50)) break;
			v.push_back(j);
			track();
		}
		cout << "#" << i << " ";
		for(auto e : v) cout << e << ".png ";
		cout << "\n";
		v.clear();
	}
}