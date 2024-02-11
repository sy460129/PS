#include <iostream>
#include <stack>
using namespace std;
stack<int>si, si2;
stack<char>sc, sc2;
int main(){
	string s; cin >> s;
	int t=-1, c, x;
	for(int i=0; i<s.length(); i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			if(t==-1) t=0;
			t*=10;
			t+=s[i]-'0';
		}
		else{
			if(t!=-1) si.push(t), t=-1;
			if(s[i]=='(') sc.push('(');
			else if(s[i]==')'){
				if(!sc.empty() && (sc.top()=='>' || sc.top()=='<')){
					c=si.top(); si.pop();
					x=si.top(); si.pop();
					if(sc.top()=='>') si.push(max(c,x));
					else si.push(min(c,x));
					sc.pop();
				}
				while(sc.top()!='('){
					si2.push(si.top()); si.pop();
					sc2.push(sc.top()); sc.pop();
				}
				if(sc.top()=='(') si2.push(si.top()), si.pop(), sc.pop();
				while(!sc2.empty()){
					c=si2.top(); si2.pop();
					x=si2.top(); si2.pop();
					if(sc2.top()=='<') si2.push(min(c,x));
					else if(sc2.top()=='>') si2.push(max(c,x));
					else if(sc2.top()=='-') si2.push(c-x);
					else si2.push(c+x);
					sc2.pop();
				}
				si.push(si2.top()); si2.pop();
				t=-1;
			}
			else{
				if(!sc.empty() && (sc.top()=='>' || sc.top()=='<')){
					c=si.top(); si.pop();
					x=si.top(); si.pop();
					if(sc.top()=='>') si.push(max(c,x));
					else si.push(min(c,x));
					sc.pop();
					t=-1;
				}
				sc.push(s[i]);
				if(s[i]=='>' || s[i]=='<') i++;
			}
		}
	}
	if(t!=-1) si.push(t);
	if(!sc.empty() && (sc.top()=='>' || sc.top()=='<')){
		c=si.top(); si.pop();
		x=si.top(); si.pop();
		if(sc.top()=='>') si.push(max(c,x));
		else si.push(min(c,x));
		sc.pop();
	}
	while(!sc.empty()){
		si2.push(si.top()); si.pop();
		sc2.push(sc.top()); sc.pop();
	}
	si2.push(si.top());
	while(!sc2.empty()){
		c=si2.top(); si2.pop();
		x=si2.top(); si2.pop();
		if(sc2.top()=='<') si2.push(min(c,x));
		else if(sc2.top()=='>') si2.push(max(c,x));
		else if(sc2.top()=='-') si2.push(c-x);
		else si2.push(c+x);
		sc2.pop();
	}
	cout << si2.top();
}