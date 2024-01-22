#include <iostream>
#include <queue>
using namespace std;
queue<int>q[26];
int main() {
	int cnt=0, k=0, t=-1;
	string s, c;
	cin >> s >> c;
	for(int i=0; i<s.length(); i++){
		q[s[i]-'a'].push(i);
	}
	while(1){
		if(q[c[k]-'a'].empty()){
			break;
		}
		else if(q[c[k]-'a'].front()<t){
			q[c[k]-'a'].pop();
		}
		else{
			if(q[c[k]-'a'].front()>t){
				t=q[c[k]-'a'].front();
				q[c[k]-'a'].pop();
				k++;
				if(k==c.length()){
					cnt++;
					k=0, t=-1;
				}
			}
			
		}
	}
	cout << cnt;
}