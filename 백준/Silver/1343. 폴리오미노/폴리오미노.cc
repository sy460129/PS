#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int>q;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='X') q.push(i);
		else{
			if((int)(q.size())%2){
				cout << -1;
				return 0;
			}
			else{
				while(!q.empty()){
					if((int)(q.size())>=4){
						for(int j=0; j<4; j++){
							s[q.front()]='A';
							q.pop();
						}
					}
					else{
						for(int j=0; j<2; j++){
							s[q.front()]='B';
							q.pop();
						}
					}
				}
			}
		}
	}
	if(!q.empty()){
		if((int)(q.size())%2){
			cout << -1;
			return 0;
		}
		else{
			while(!q.empty()){
				if((int)(q.size())>=4){
					for(int j=0; j<4; j++){
						s[q.front()]='A';
						q.pop();
					}
				}
				else{
					for(int j=0; j<2; j++){
						s[q.front()]='B';
						q.pop();
					}
				}
			}
		}
	}
	cout << s;
}