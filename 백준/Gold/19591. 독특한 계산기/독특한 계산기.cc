#include <iostream>
#include <deque>
#include <string>
using namespace std;
using ll=long long;
deque<ll>d;
deque<char>d2;
int main() {
	ll x, y, z, w;
	string c, s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(i && (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')){
			d.push_back(stoll(c));
			c="";
			d2.push_back(s[i]);
		}
		else c+=s[i];
	}
	d.push_back(stoll(c));
	if(d.size()==1){
		cout << d.front();
		return 0;
	}
	while(d.size()!=2){
		x=d.front();
		y=d.back();
		if((d2.front()=='*' || d2.front()=='/') && (d2.back()!='*' && d2.back()!='/')) {
			d.pop_front();
			z=d.front();
			d.pop_front();
			if(d2.front()=='*') d.push_front(x*z);
			else d.push_front(x/z);
			d2.pop_front();
		}
		else if((d2.back()=='*' || d2.back()=='/') && (d2.front()!='*' && d2.front()!='/')){
			d.pop_back();
			w=d.back();
			d.pop_back();
			if(d2.back()=='*') d.push_back(y*w);
			else d.push_back(w/y);
			d2.pop_back();
		}
		else if((d2.front()=='*' || d2.front()=='/') && (d2.back()=='*' || d2.back()=='/')){
			d.pop_back();
			d.pop_front();
			z=d.front();
			w=d.back();
			if(d2.front()=='*') z*=x;
			else z=x/z;
			if(d2.back()=='*') w*=y;
			else w/=y;
			if(z>=w){
				d.push_back(y);
				d.pop_front();
				d.push_front(z);
				d2.pop_front();
			}
			else{
				d.push_front(x);
				d.pop_back();
				d.push_back(w);
				d2.pop_back();
			}
		}
		else{
			d.pop_back();
			d.pop_front();
			z=d.front();
			w=d.back();
			if(d2.front()=='+') z+=x;
			else z=x-z;
			if(d2.back()=='+') w+=y;
			else w-=y;
			if(z>=w){
				d.push_back(y);
				d.pop_front();
				d.push_front(z);
				d2.pop_front();
			}
			else{
				d.push_front(x);
				d.pop_back();
				d.push_back(w);
				d2.pop_back();
			}
		}
	}
	char ch=d2.front();
	x=d.front(), y=d.back();
	if(ch=='+') cout << x+y;
	else if(ch=='-') cout << x-y;
	else if(ch=='*') cout << x*y;
	else cout << x/y;
}