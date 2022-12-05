#include <iostream>
#include <vector>
using namespace std;
int arr[26];
int main(){
	vector<char>v;
	bool c=true;
	string s;
	int n;
	getline(cin, s);
	cin >> n;
	for(int i=0; i<26; i++){
		cin >> arr[i];
	}
	for(int i=0; i<s.length(); i++){
		s[i]=towupper(s[i]);
		if(i==0) arr[s[i]-'A']--, v.push_back(s[i]);
		else{
			if(s[i-1]==s[i]) continue;
			else if(s[i]==' ') n--;
			else arr[s[i]-'A']--;
			if(s[i]!=' ' && s[i-1]==' ') v.push_back(s[i]);
		}
	}
	for(int i=0; i<v.size(); i++) arr[v[i]-'A']--;
	for(int i=0; i<26; i++){
		if(arr[i]<0) c=false;
	}
	if(n<0 || !c) cout << -1;
	else{
		for(auto e : v) cout << e;
	}
}