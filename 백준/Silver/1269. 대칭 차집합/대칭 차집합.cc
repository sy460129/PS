#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int>s;
	int n, m, x;
	cin >> n >> m;
	while(n--){
		cin >> x;
		s.insert(x);
	}
	while(m--){
		cin >> x;
		if(s.find(x)!=s.end()){
			s.erase(x);
		}
		else{
			s.insert(x);
		}
	}
	cout << s.size();
}