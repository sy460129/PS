#include <iostream>
#include <vector>
using namespace std;
bool check, ch;
int main(){
	string s, c;
	int n, cnt=0;
	vector<char>v;
	cin >> s >> n;
	while(n--){
		ch=false;
		cin >> c;
		c+=c;
		for(int i=0; i<c.length(); i++){
			v.push_back(c[i]);
			if(v.back()==s[s.length()-1]){
				check=true;
				for(int j=0; j<s.length(); j++){
					if(v[v.size()-j-1]!=s[s.length()-j-1]){
						check=false;
					}
				}
				if(check){
					cnt++;
					ch=true;
				}
			}
			if(ch){
				break;
			}
		}
	}
	cout << cnt;
}