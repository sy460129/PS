#include <iostream>
#include <queue>
using namespace std;
queue<int>b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int cnt=0;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='C' && !b.empty()){
			s[b.front()]='x';
			b.pop();
			cnt++;
		}
		else if(s[i]=='B') b.push(i);
	}
	for(int i=0; i<s.length(); i++){
		if(s[i]=='A'){
            while(!b.empty() && (b.front()<i || s[b.front()]=='x')) b.pop();
            if(!b.empty()) cnt++, b.pop();
            else break;
		}
	}
	cout << cnt;
}