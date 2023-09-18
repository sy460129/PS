#include <iostream>
#include <deque>
using namespace std;
deque<char>d;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, status=0, b=0, w=0; cin >> n;
	// 0 : 뒤 ==== 앞
	// 1 :  뒤 
	//		||
	//	    ||
	//	    앞
	// 2 : 앞 ==== 뒤
	// 3 :	앞 
	//		||
	//	    ||
	//		뒤
	string s;
	char m;
	while(n--){
		cin >> s;
 		if(s=="push"){
			cin >> m;
			if(m=='b'){
				if((status==1 && !w) || status==3) continue;
				else d.push_back('b'), b++;
			}
			else d.push_back('w'), w++;
		}
		else if(s=="rotate"){
			cin >> m;
			m=='r' ? status++ : status--;
			if(status>3) status=0;
			if(status<0) status=3;
			if(status==1){
				while(!d.empty() && d.front()=='b') d.pop_front(), b--;
			}
			else if(status==3){
				while(!d.empty() && d.back()=='b') d.pop_back(), b--;
			}
		}
		else if(s=="pop"){
			if(!d.empty()){
				d.front()=='b' ? b-- : w--;
				d.pop_front();
				if(status==1){
					while(!d.empty() && d.front()=='b') d.pop_front(), b--;
				}
			}
		}
		else if(s=="count"){
			cin >> m;
			m=='b' ? cout << b << "\n" : cout << w << "\n";
		}
	}
}