#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, p, x, y; cin >> n;
	set<pair<int,int>>s;
	map<int,int>m;
	while(n--){
		cin >> x >> y;
		s.insert({y,x});
		m[x]=y;
	}
	string c;
	cin >> p;
	while(p--){
		cin >> c;
		if(c=="add"){
			cin >> x >> y;
			s.insert({y,x});
			m[x]=y;
		}
		else if(c=="solved"){
			cin >> x;
			s.erase({m[x],x});
		}
		else{
			cin >> x;
			if(x==1){
				auto it=s.end();
				cout << (--it)->second << "\n";
			}
			else{
				auto it=s.begin();
				cout << it->second << "\n";
			}
		}
	}
}
